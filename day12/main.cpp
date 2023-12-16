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

map<pair<pair<int, int>, int>, int> mp;
int solve(vector<int> &sizes, string &group, int i, int j, int csize) {
  if (mp.count({{i, j}, csize}))
    return mp[{{i, j}, csize}];
  if (j == group.size()) {
    if ((i == sizes.size() && csize == 0) ||
        (i == sizes.size() - 1 && csize == sizes.back())) {
      return 1;
    }
    return 0;
  }

  if (i > sizes.size()) {
    return 0;
  }
  if (i == sizes.size() && csize > 0) {
    return 0;
  }
  if (i < sizes.size() && csize > sizes[i]) {
    return 0;
  }

  if (group[j] == '.') {
    if (i < sizes.size() && sizes[i] == csize) {
      mp[{{i, j}, csize}] = solve(sizes, group, i + 1, j + 1, 0);
      return mp[{{i, j}, csize}];
    }
    if (csize == 0) {
      mp[{{i, j}, csize}] = solve(sizes, group, i, j + 1, 0);
      return mp[{{i, j}, csize}];
    }
  }

  if (group[j] == '#') {
    mp[{{i, j}, csize}] = solve(sizes, group, i, j + 1, csize + 1);
    return mp[{{i, j}, csize}];
  }

  if (group[j] == '?') {
    if (i < sizes.size() && sizes[i] == csize) {
      mp[{{i, j}, csize}] = solve(sizes, group, i + 1, j + 1, 0);
      return mp[{{i, j}, csize}];
    }
    if (csize == 0) {
      mp[{{i, j}, csize}] = solve(sizes, group, i, j + 1, csize + 1) +
                            solve(sizes, group, i, j + 1, 0);
      return mp[{{i, j}, csize}];
    }
    mp[{{i, j}, csize}] = solve(sizes, group, i, j + 1, csize + 1);
    return mp[{{i, j}, csize}];
  }

  mp[{{i, j}, csize}] = 0;
  return 0;
}

void p1() {
  string line;
  vector<string> lines;
  vector<string> sizes_str;
  vector<int> sizes;
  int ans = 0;
  while (getline(cin, line)) {
    lines.clear();
    sizes_str.clear();
    sizes.clear();
    lines = split(line, ' ');
    string group = lines[0];

    sizes_str = split(lines[1], ',');
    for (string &s : sizes_str) {
      sizes.pb(stoi(s));
    }
    int cur = solve(sizes, group, 0, 0, 0);
    ans += cur;
    mp.clear();
  }

  cout << ans << endl;
}

void p2() {
  string line;
  vector<string> lines;
  vector<string> sizes_str;
  vector<int> sizes;
  int ans = 0;
  while (getline(cin, line)) {
    lines.clear();
    sizes_str.clear();
    sizes.clear();
    lines = split(line, ' ');
    string group = lines[0] + "?" + lines[0] + "?" + lines[0] + "?" + lines[0] + "?" + lines[0];

    sizes_str = split(lines[1], ',');
    for (int i = 0; i < 5; i++) {
      for (string &s : sizes_str) {
        sizes.pb(stoi(s));
      }
    }
    int cur = solve(sizes, group, 0, 0, 0);
    ans += cur;
    mp.clear();
  }

  cout << ans << endl;
}

// --------------------Snippet-Ends--------------------------------

signed main() {
  FASTIO
  p2();
  return 0;
}
