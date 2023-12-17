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

void rotate(vector<vector<char>> &mp) {
  vector<vector<char>> tmp(mp[0].size(), vector<char>());

  int r = 0;
  int c = 0;
  for (int i = mp.size() - 1; i >= 0; i--) {
    for (int j = 0; j < mp[i].size(); j++) {
      tmp[j].pb(mp[i][j]);
    }
  }

  mp = tmp;
}

void p1() {
  vector<vector<char>> mp;
  string line;
  vector<pair<int, int>> round;
  map<int, set<int>>
      square; // key is column of map, set contains locations of squares
  while (getline(cin, line)) {
    mp.pb(vector<char>());
    for (char &c : line) {
      if (c == 'O') {
        round.pb({mp.size() - 1, mp.back().size()});
      }
      mp.back().pb(c);
    }
  }

  sort(round.begin(), round.end());

  int ans = 0;
  for (auto &i : round) {
    int row = i.first;
    while (row - 1 >= 0 && mp[row - 1][i.second] == '.') {
      row--;
    }
    mp[i.first][i.second] = '.';
    mp[row][i.second] = 'O';

    ans += mp.size() - (row);
  }

  cout << ans << endl;
}

void p2() {
  vector<vector<char>> mp;
  map<vector<pair<int, int>>, int> mem;
  string line;
  vector<pair<int, int>> round;
  map<int, set<int>>
      square; // key is column of map, set contains locations of squares
  while (getline(cin, line)) {
    mp.pb(vector<char>());
    for (char &c : line) {
      if (c == 'O') {
        round.pb({mp.size() - 1, mp.back().size()});
      }
      mp.back().pb(c);
    }
  }

  for (int i = 0; i < 1000000000; i++) {
    if (mem.count(round)) {
      int diff = i - mem[round];
      i += ((1000000000 - i) / diff * diff);
    }
    mem[round] = i;
    for (int l = 0; l < 4; l++) {
      for (auto &j : round) {
        int row = j.first;
        while (row - 1 >= 0 && mp[row - 1][j.second] == '.') {
          row--;
        }
        mp[j.first][j.second] = '.';
        mp[row][j.second] = 'O';
      }

      round.clear();
      rotate(mp);

      for (int j = 0; j < mp.size(); j++) {
        for (int k = 0; k < mp[j].size(); k++) {
          if (mp[j][k] == 'O') {
            round.pb({j, k});
          }
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < mp.size(); i++) {
    for (int j = 0; j < mp[i].size(); j++) {
      if (mp[i][j] == 'O') {
        ans += mp.size() - i;
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
