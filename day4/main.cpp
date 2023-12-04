#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define int ll
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0), cin.tie(0);

// --------------------Snippet-Ends--------------------------------

signed main() {
  string line;
  int ans = 0;
  vector<int> card_wins;
  while (getline(cin, line)) {
    vector<string> win_nums;
    vector<string> cur_nums;
    int i = 0;
    while (line[i] != ':') {
      i++;
    }
    i++;
    while (!isdigit(line[i])) {
      i++;
    }
    while (line[i] != '|') {
      string cur = "";
      while (isdigit(line[i])) {
        cur += line[i];
        i++;
      }
      while (line[i] == ' ') {
        i++;
      }
      win_nums.pb(cur);
    }

    while (!isdigit(line[i])) {
      i++;
    }
    while (i < line.size()) {
      string cur = "";
      while (isdigit(line[i])) {
        cur += line[i];
        i++;
      }
      while (line[i] == ' ') {
        i++;
      }
      cur_nums.pb(cur);
    }

    int cur = 0;

    for (string &s1 : cur_nums) {
      for (string &s2 : win_nums) {
        if (s1 == s2) {
          cur++;
        }
      }
    }
    card_wins.pb(cur);
  }

  vector<int> copies(card_wins.size(), 1);
  
  for (int i=0; i<card_wins.size(); i++) {
    for (int j=1; i + j < card_wins.size() && j<=card_wins[i]; j++) {
      copies[i + j]+=copies[i];
    }
  }

  for (int i=0; i<copies.size(); i++) {
    ans += copies[i];
  }
  cout << ans << endl;

  return 0;
}
