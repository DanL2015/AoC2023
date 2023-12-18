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

void p1() {
  vector<vector<char>> mp;
  string line;
  while (getline(cin, line)) {
    mp.pb(vector<char>());
    for (char &c : line) {
      mp.back().pb(c);
    }
  }

  queue<pair<pair<int, int>, pair<int, int>>> q; // location and direction
  map<pair<pair<int, int>, pair<int, int>>, bool> vis;

  //lmao fuck it just hardcode the starting tile direction
  q.push({{0, 0}, {1, 0}});
  vis[{{0, 0}, {1, 0}}] = true;

  while (!q.empty()) {
    pair<int, int> cur = q.front().first;
    pair<int, int> dir = q.front().second;

    q.pop();

    pair<int, int> next = {cur.first + dir.first, cur.second + dir.second};

    if (next.first < 0 || next.second < 0 || next.first >= mp.size() ||
        next.second >= mp[next.first].size())
      continue;

    if (vis.count({next, dir})) continue;

    vis[{next, dir}] = true;
    char tile = mp[next.first][next.second];
    if (tile == '.') {
      q.push({next, dir});
    }
    else if (tile == '\\') {
      q.push({next, {dir.second, dir.first}});
    } else if (tile == '/') {
      q.push({next, {-1 * dir.second, -1 * dir.first}});
    } else if (tile == '-') {
      if (dir.first != 0) {
        q.push({next, {dir.second, dir.first}});
        q.push({next, {dir.second, -1 * dir.first}});
      } else {
        q.push({next, dir});
      }
    } else if (tile == '|') {
      if (dir.second != 0) {
        q.push({next, {dir.second, dir.first}});
        q.push({next, {-1 * dir.second, dir.first}});
      } else {
        q.push({next, dir});
      }
    }
  }

  vector<vector<bool>> energized(mp.size(), vector<bool>(mp[0].size(), false));

  for (auto it : vis) {
    energized[it.first.first.first][it.first.first.second] = true;
  }

  int ans = 0;
  for (int i=0; i<energized.size(); i++) {
    for (int j=0; j<energized[i].size(); j++) {
      ans += energized[i][j];
    }
  }
  cout << ans << endl;
}

int bfs(vector<vector<char>> &mp, pair<pair<int, int>, pair<int, int>> start) {
  //we just start the bfs at 1 before the actual position
  queue<pair<pair<int, int>, pair<int, int>>> q; // location and direction
  map<pair<pair<int, int>, pair<int, int>>, bool> vis;

  q.push(start);

  while (!q.empty()) {
    pair<int, int> cur = q.front().first;
    pair<int, int> dir = q.front().second;

    q.pop();

    pair<int, int> next = {cur.first + dir.first, cur.second + dir.second};

    if (next.first < 0 || next.second < 0 || next.first >= mp.size() ||
        next.second >= mp[next.first].size())
      continue;

    if (vis.count({next, dir})) continue;

    vis[{next, dir}] = true;
    char tile = mp[next.first][next.second];
    if (tile == '.') {
      q.push({next, dir});
    }
    else if (tile == '\\') {
      q.push({next, {dir.second, dir.first}});
    } else if (tile == '/') {
      q.push({next, {-1 * dir.second, -1 * dir.first}});
    } else if (tile == '-') {
      if (dir.first != 0) {
        q.push({next, {dir.second, dir.first}});
        q.push({next, {dir.second, -1 * dir.first}});
      } else {
        q.push({next, dir});
      }
    } else if (tile == '|') {
      if (dir.second != 0) {
        q.push({next, {dir.second, dir.first}});
        q.push({next, {-1 * dir.second, dir.first}});
      } else {
        q.push({next, dir});
      }
    }
  }

  vector<vector<bool>> energized(mp.size(), vector<bool>(mp[0].size(), false));

  for (auto it : vis) {
    energized[it.first.first.first][it.first.first.second] = true;
  }

  int ans = 0;
  for (int i=0; i<energized.size(); i++) {
    for (int j=0; j<energized[i].size(); j++) {
      ans += energized[i][j];
    }
  }
  return ans;
}

void p2() {
  vector<vector<char>> mp;
  string line;
  while (getline(cin, line)) {
    mp.pb(vector<char>());
    for (char &c : line) {
      mp.back().pb(c);
    }
  }

  int ans = 0;
  for (int i=0; i<mp.size(); i++) {
    ans = max(ans, bfs(mp, {{i, -1}, {0, 1}}));
    ans = max(ans, bfs(mp, {{i, mp[i].size()}, {0, -1}}));
  }

  for (int i=0; i<mp[0].size(); i++) {
    ans = max(ans, bfs(mp, {{-1, i}, {1, 0}}));
    ans = max(ans, bfs(mp, {{mp.size(), i}, {-1, 0}}));
  }

  cout << ans << endl;
}

// --------------------Snippet-Ends--------------------------------

signed main() {
  FASTIO
  p2();
  return 0;
}
