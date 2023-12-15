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

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void p1() {
  vector<vector<char>> mp;
  string line;
  vector<char> tmp;
  while (getline(cin, line)) {
    tmp.clear();
    for (char &c : line) {
      tmp.pb(c);
    }
    mp.pb(tmp);
    bool empty = true;
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == '#') {
        empty = false;
      }
    }
    if (empty) {
      mp.pb(tmp);
    }
  }

  for (int i=0; i<mp[0].size(); i++) {
    bool empty = true;
    for (int j=0; j<mp.size(); j++) {
      if (mp[j][i] == '#') {
        empty = false;
      }
    }
    if (empty) {
      for (int j=0; j<mp.size(); j++) {
        mp[j].insert(mp[j].begin() + i, '.');
      }
      i++;
    }
  }

  int ans = 0;

  vector<pair<int, int>> galaxies;
  for (int i=0; i<mp.size(); i++) {
    for (int j=0; j<mp[i].size(); j++) {
      if (mp[i][j] == '#') {
        galaxies.pb({i, j});
      }
    }
  }

  for (int i=0; i<galaxies.size(); i++) {
    for (int j=i+1; j<galaxies.size(); j++) {
      int dist = abs(galaxies[i].first - galaxies[j].first) + abs(galaxies[i].second - galaxies[j].second);
      ans += dist;
      cout << i << " " << j << " " << dist << endl;
    }
  }

  cout << ans << endl;
}

void p2() {
  vector<vector<char>> mp;
  string line;
  vector<char> tmp;
  set<int> rows;
  set<int> cols;
  while (getline(cin, line)) {
    tmp.clear();
    for (char &c : line) {
      tmp.pb(c);
    }
    mp.pb(tmp);
    bool empty = true;
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == '#') {
        empty = false;
      }
    }
    if (empty) {
      rows.insert(mp.size() - 1);
    }
  }

  for (int i=0; i<mp[0].size(); i++) {
    bool empty = true;
    for (int j=0; j<mp.size(); j++) {
      if (mp[j][i] == '#') {
        empty = false;
      }
    }
    if (empty) {
      cols.insert(i);
    }
  }

  int ans = 0;
  vector<pair<int, int>> galaxies;
  for (int i=0; i<mp.size(); i++) {
    for (int j=0; j<mp[i].size(); j++) {
      if (mp[i][j] == '#') {
        galaxies.pb({i, j});
      }
    }
  }

  for (int i=0; i<galaxies.size(); i++) {
    for (int j=i+1; j<galaxies.size(); j++) {
      int rs = min(galaxies[i].first, galaxies[j].first);
      int re = max(galaxies[i].first, galaxies[j].first);
      int cs = min(galaxies[i].second, galaxies[j].second);
      int ce = max(galaxies[i].second, galaxies[j].second);
      int dist = (re - rs) + (ce - cs);
      for (int k=rs; k<=re; k++) {
        if (rows.count(k)) {
          dist += 1000000;
          dist -= 1;
        }
      }
      for (int k=cs; k<=ce; k++) {
        if (cols.count(k)) {
          dist += 1000000;
          dist -= 1;
        }
      }
      ans += dist;
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
