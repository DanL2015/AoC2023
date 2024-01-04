#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define pb push_back
#define ll long long
#define int ll
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0), cin.tie(0);

struct deb {
  int r;
  int c;
  int d;
};

struct state {
  int loss;
  int consec;
  int r;
  int c;
  int d;
  vector<deb> path;

  bool operator<(const state &o) const { return loss > o.loss; }
};

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
  string line;
  vector<vector<int>> mp;
  while (getline(cin, line)) {
    mp.pb(vector<int>());
    for (char &c : line) {
      mp.back().pb(c - '0');
    }
  }

  priority_queue<state> q;
  map<pair<pair<pair<int, int>, int>, int>, int> vis; //visited based on position, direction, consecutive blocks
                                                                 //please kill me
  q.push(state{0, 1, 0, 0, 0, {deb{0, 0, 0}}});
  q.push(state{0, 1, 0, 0, 1, {deb{0, 0, 0}}});

  pair<int, int> dir[3] = {{0, 1}, {1, 0}, {-1, 0}};

  while (!q.empty()) {
    state cur = q.top();
    cout << "Current: " << cur.r << " " << cur.c << endl;
    q.pop();

    if (cur.r == mp.size() - 1 && cur.c == mp[cur.r].size() - 1) {
      for (auto it : cur.path) {
        cout << it.r << " " << it.c << " " << it.d << endl;
      }
      cout << cur.loss << endl;
      break;
    }
    
    for (int i=0; i<3; i++) {
      state next;
      next.r = cur.r + dir[i].first;
      next.c = cur.c + dir[i].second;
      next.d = i;
      next.consec = (cur.d == i ? cur.consec + 1 : 0);
      if ((cur.d == 1 && i == 2) || (cur.d == 2 && i == 1)) continue;
      if (next.r < 0 || next.c < 0 || next.r >= mp.size() || next.c >= mp[next.r].size()) continue;
      if (next.consec >= 3) continue;
      next.loss = cur.loss + mp[next.r][next.c];
      next.path = cur.path;
      next.path.pb(deb{next.r, next.c, next.loss});
      if (!vis.count({{{next.r, next.c}, cur.d}, next.consec}) || vis[{{{next.r, next.c}, cur.d}, next.consec}] > cur.loss) {
        cout << "Pushing: " << next.r << " " << next.c << " " << next.consec << endl;
        vis[{{{next.r, next.c}, cur.d}, next.consec}] = cur.loss;
        q.push(next);
      }
    }
  }

  vector<vector<int>> res(mp.size(), vector<int>(mp[0].size(), INT_MAX));
  for (auto it : vis) {
    if (res[it.first.first.first.first][it.first.first.first.second] > it.second) {
      res[it.first.first.first.first][it.first.first.first.second] = it.second;
    }
  }

}

void p2() {}

// --------------------Snippet-Ends--------------------------------

signed main() {
  FASTIO
  p1();
  return 0;
}
