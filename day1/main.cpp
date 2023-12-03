#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define pb push_back
#define ll long long
#define int ll
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0);

// --------------------Snippet-Ends--------------------------------

signed main() {
  FASTIO
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  map<string, int> mp;
  mp["one"] = 1;
  mp["two"] = 2;
  mp["three"] = 3;
  mp["four"] = 4;
  mp["five"] = 5;
  mp["six"] = 6;
  mp["seven"] = 7;
  mp["eight"] = 8;
  mp["nine"] = 9;

  int ans = 0;
  string line;
  while (getline(cin, line)) {
    int fst = -1;
    int lst = -1;
    for (int i = 0; i < line.size(); i++) {
      for (auto it = mp.begin(); it != mp.end(); it++) {
        if (line.size() - i < it->first.size()) {
          continue;
        }
        if (line.substr(i, it->first.size()) == it->first) {
          fst = fst == -1 ? it->second : fst;
          lst = it->second;
        }
      }
      if (isdigit(line[i])) {
        fst = fst == -1 ? line[i] - '0' : fst;
        lst = line[i] - '0';
      }
    }
    ans += fst * 10 + lst;
  }

  cout << ans;
  return 0;
}
