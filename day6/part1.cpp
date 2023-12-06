#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define int ll
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0), cin.tie(0);

// --------------------Snippet-Ends--------------------------------

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

signed main() {
  FASTIO
  string line;
  vector<int> times;
  vector<int> dists;
  getline(cin, line);
  vector<string> strs = split(line, ' ');
  strs.erase(strs.begin());
  for (string &str : strs) {
    times.pb(stol(str));
  }
  getline(cin, line);
  strs = split(line, ' ');
  strs.erase(strs.begin());
  for (string &str : strs) {
    dists.pb(stol(str));
  }

  int ans = 1;

  for (int i=0; i<times.size(); i++) {
    int time = times[i];
    int dist = dists[i];
    int cur = 0;

    for (int j=1; j<time; j++) {
      int res = j * (time - j);
      if (res > dist) {
        cur++;
      }
    }
    ans *= cur;
  }
  cout << ans << endl;

  return 0;
}
