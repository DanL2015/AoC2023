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

  string lines;
  getline(cin, lines);
  vector<string> seed_str = split(lines, ' ');
  seed_str.erase(seed_str.begin());
  vector<int> seed;
  for (string &str : seed_str) {
    seed.pb(stol(str));
  }
  getline(cin, lines);

  for (int k = 0; k < 7; k++) {
    getline(cin, lines);
    vector<int> seed_prev = seed;
    while (getline(cin, lines) && lines != "") {
      vector<string> i = split(lines, ' ');
      int dest = stol(i[0]);
      int source = stol(i[1]);
      int range = stol(i[2]);
      
      for (int j = 0; j<seed.size(); j++) {
        if (seed_prev[j] >= source && seed_prev[j] < source + range) {
          seed[j] = dest + (seed_prev[j] - source);
        }
      }
    }
  }

  sort(seed.begin(), seed.end());
  cout << seed[0] << endl;

  return 0;
}
