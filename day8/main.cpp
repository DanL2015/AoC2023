#include <bits/stdc++.h>
#include <numeric>
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
  string dirs;
  string line;
  vector<string> strs;
  map<string, pair<string, string>> paths;
  string curpath = "AAA";
  getline(cin, line);
  dirs = line;
  getline(cin, line);
  while (getline(cin, line)) {
    strs = split(line, ' ');
    paths[strs[0]] = {strs[2].substr(1, 3), strs[3].substr(0, 3)};
  }
  int ans = 0;

  while (curpath != "ZZZ") {
    char ndir = dirs[ans % dirs.size()];
    if (ndir == 'R') {
      curpath = paths[curpath].second;
    } else {
      curpath = paths[curpath].first;
    }
    ans++;
  }
  cout << ans << endl;
  return;
}

void p2() {
  string dirs;
  string line;
  vector<string> strs;
  map<string, pair<string, string>> paths;
  vector<string> curpaths;
  getline(cin, line);
  dirs = line;
  getline(cin, line);
  while (getline(cin, line)) {
    strs = split(line, ' ');
    paths[strs[0]] = {strs[2].substr(1, 3), strs[3].substr(0, 3)};
    if (strs[0][2] == 'A') {
      curpaths.pb(strs[0]);
    }
  }
  vector<int> ans_paths;

  for (int i=0; i<curpaths.size(); i++) {
    string curpath = curpaths[i];
    int ans = 0;
    while (curpath[2] != 'Z') {
      char ndir = dirs[ans % dirs.size()];
      if (ndir == 'R') {
        curpath = paths[curpath].second;
      } else {
        curpath = paths[curpath].first;
      }
      ans++;
    }
    ans_paths.pb(ans);
  }

  //find lcm of all ans
  int res = 1;
  for (int i=0; i<ans_paths.size(); i++) {
    res = lcm(res, ans_paths[i]);
  }
  cout << res << endl;

  return;
}

// --------------------Snippet-Ends--------------------------------

signed main() {
  FASTIO
  p2();
  return 0;
}
