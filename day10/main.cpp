#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define int ll
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0), cin.tie(0);

vector<string> split(string &s, char c) {
  string cur = "";
  vector<string> ans;
  for (char &i : s) {
    if (i == c) {
      if (cur != "") {
        ans.push_back(cur);
        cur = "";
      }
    } else {
      cur += i;
    }
  }
  if (cur != "") {
    ans.push_back(cur);
  }
  return ans;
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool con(pair<int, int> i1, pair<int, int> o1, pair<int, int> i2,
         pair<int, int> o2) {
  return (i1.first == i2.first && i1.second == i2.second) ||
         (i1.first == o2.first && i1.second == o2.second) ||
         (o1.first == i2.first && o1.second == i2.second) ||
         (o1.first == o2.first && o1.second == o2.second);
}

void neg(pair<int, int> &tmp) {
  tmp.first = -1 * tmp.first;
  tmp.second = -1 * tmp.second;
}

void p1() {
  pair<int, int> st;
  vector<vector<char>> mp;
  string line;
  while (getline(cin, line)) {
    mp.pb(vector<char>());
    for (char &c : line) {
      mp.back().pb(c);
      if (c == 'S') {
        st = {mp.size() - 1, mp.back().size() - 1};
      }
    }
  }

  map<char, vector<pair<int, int>>> c_dir;
  c_dir['|'] = {{-1, 0}, {1, 0}};
  c_dir['-'] = {{0, -1}, {0, 1}};
  c_dir['L'] = {{-1, 0}, {0, 1}};
  c_dir['J'] = {{-1, 0}, {0, -1}};
  c_dir['7'] = {{1, 0}, {0, -1}};
  c_dir['F'] = {{1, 0}, {0, 1}};
  c_dir['S'] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  c_dir['.'] = {};

  queue<pair<int, pair<int, int>>> q;
  vector<vector<int>> vis(mp.size(), vector<int>(mp[0].size(), -1));

  q.push({1, st});
  vis[st.first][st.second] = 0;

  while (!q.empty()) {
    int cdist = q.front().first;
    pair<int, int> cur = q.front().second;
    q.pop();

    for (int i = 0; i < c_dir[mp[cur.first][cur.second]].size(); i++) {
      pair<int, int> n = c_dir[mp[cur.first][cur.second]][i];
      int nr = cur.first + n.first;
      int nc = cur.second + n.second;
      neg(n);
      if (nr < 0 || nc < 0 || nr >= mp.size() || nc >= mp[nr].size() ||
          vis[nr][nc] != -1)
        continue;
      bool con = false;
      for (pair<int, int> j : c_dir[mp[nr][nc]]) {
        if (n == j) {
          con = true;
          break;
        }
      }
      if (con) {
        vis[nr][nc] = cdist;
        q.push({cdist + 1, {nr, nc}});
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < vis.size(); i++) {
    for (int j = 0; j < vis[i].size(); j++) {
      ans = max(ans, vis[i][j]);
    }
  }
  cout << ans << endl;
}

void p2() {
  pair<int, int> st;
  vector<vector<char>> mp;
  string line;
  while (getline(cin, line)) {
    mp.pb(vector<char>(line.size() * 2 + 1, '.'));
    mp.pb(vector<char>());
    mp.back().pb('.');
    for (char &c : line) {
      mp.back().pb(c);
      if (c == 'S') {
        st = {mp.size() - 1, mp.back().size() - 1};
      }
      mp.back().pb('.');
    }
  }
  mp.pb(vector<char>(mp.back().size(), '.'));

  map<char, vector<pair<int, int>>> c_dir;
  c_dir['|'] = {{-2, 0}, {2, 0}};
  c_dir['-'] = {{0, -2}, {0, 2}};
  c_dir['L'] = {{-2, 0}, {0, 2}};
  c_dir['J'] = {{-2, 0}, {0, -2}};
  c_dir['7'] = {{2, 0}, {0, -2}};
  c_dir['F'] = {{2, 0}, {0, 2}};
  c_dir['S'] = {{2, 0}, {0, 2}, {-2, 0}, {0, -2}};
  c_dir['.'] = {};

  queue<pair<int, pair<int, int>>> q;
  vector<vector<int>> vis(mp.size(), vector<int>(mp[0].size(), 0));

  q.push({1, st});
  vis[st.first][st.second] = 1;

  while (!q.empty()) {
    int cdist = q.front().first;
    pair<int, int> cur = q.front().second;
    q.pop();

    for (int i = 0; i < c_dir[mp[cur.first][cur.second]].size(); i++) {
      pair<int, int> n = c_dir[mp[cur.first][cur.second]][i];
      int nr = cur.first + n.first;
      int nc = cur.second + n.second;
      neg(n);
      if (nr < 0 || nc < 0 || nr >= mp.size() || nc >= mp[nr].size())
        continue;
      if (vis[nr][nc] != 0) {
        vis[nr + n.first / 2][nc + n.second / 2] = cdist;
        continue;
      }
      bool con = false;
      for (pair<int, int> j : c_dir[mp[nr][nc]]) {
        if (n == j) {
          con = true;
          break;
        }
      }
      if (con) {
        vis[nr][nc] = cdist;
        vis[nr + n.first / 2][nc + n.second / 2] = cdist;
        q.push({cdist, {nr, nc}});
      }
    }
  }

  // loop is marked by -2;
  int ans = 0;
  for (int i = 0; i < vis.size(); i++) {
    for (int j = 0; j < vis[i].size(); j++) {
      // floodfill
      if (vis[i][j] == 0) {
        bool enclosed = true;
        int num = (i % 2 == 1 && j % 2 == 1);
        queue<pair<int, int>> cq;
        cq.push({i, j});
        vis[i][j] = 2;

        while (!cq.empty()) {
          pair<int, int> cur = cq.front();
          cq.pop();
          for (int k = 0; k < 4; k++) {
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];
            if (nx < 0 || ny < 0 || nx >= vis.size() || ny >= vis[nx].size()) {
              enclosed = false;
              continue;
            }
            if (vis[nx][ny] != 0)
              continue;
            vis[nx][ny] = 2;
            if (nx % 2 == 1 && ny % 2 == 1) {
              vis[nx][ny] = 5;
              num++;
            }
            cq.push({nx, ny});
          }
        }
        if (enclosed) {
          ans += num;
        }
      }
    }
  }
  cout << ans << endl;
}

// --------------------Snippet-Ends--------------------------------

signed main() {
  FASTIO
  p2();
  return 0;
}
