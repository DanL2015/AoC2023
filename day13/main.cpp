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
  int ans = 0;
  while (true) {
    vector<vector<char>> mp;
    string line;
    while (getline(cin, line)) {
      if (line == "")
        break;
      mp.pb(vector<char>());
      for (char &c : line) {
        mp.back().pb(c);
      }
    }

    if (mp.size() == 0)
      break;

    int n_rows = mp.size();
    int n_cols = mp[0].size();

    for (int i = 0; i < n_rows - 1; i++) {
      int top = i;
      int bot = i + 1;
      bool cont = true;
      while (top >= 0 && bot < n_rows) {
        for (int j = 0; j < n_cols; j++) {
          if (mp[top][j] != mp[bot][j]) {
            cont = false;
          }
        }
        if (!cont)
          break;
        top--;
        bot++;
      }
      if (cont) {
        ans += (i + 1) * 100;
      }
    }

    for (int i = 0; i < n_cols - 1; i++) {
      int left = i;
      int right = i + 1;
      bool cont = true;
      while (left >= 0 && right < n_cols) {
        for (int j = 0; j < n_rows; j++) {
          if (mp[j][left] != mp[j][right]) {
            cont = false;
          }
        }
        if (!cont)
          break;
        left--;
        right++;
      }
      if (cont) {
        ans += i + 1;
      }
    }
  }
  cout << ans << endl;
}

void p2() {
  int ans = 0;
  while (true) {
    vector<vector<char>> mp;
    string line;
    while (getline(cin, line)) {
      if (line == "")
        break;
      mp.pb(vector<char>());
      for (char &c : line) {
        mp.back().pb(c);
      }
    }

    if (mp.size() == 0)
      break;

    int n_rows = mp.size();
    int n_cols = mp[0].size();

    for (int i = 0; i < n_rows - 1; i++) {
      int top = i;
      int bot = i + 1;
      int cont = 0;
      while (top >= 0 && bot < n_rows) {
        for (int j = 0; j < n_cols; j++) {
          if (mp[top][j] != mp[bot][j]) {
            cont++;
          }
        }
        if (cont > 1)
          break;
        top--;
        bot++;
      }
      if (cont == 1) {
        ans += (i + 1) * 100;
      }
    }

    for (int i = 0; i < n_cols - 1; i++) {
      int left = i;
      int right = i + 1;
      int cont = 0;
      while (left >= 0 && right < n_cols) {
        for (int j = 0; j < n_rows; j++) {
          if (mp[j][left] != mp[j][right]) {
            cont++;
          }
        }
        if (cont > 1)
          break;
        left--;
        right++;
      }
      if (cont == 1) {
        ans += i + 1;
      }
    }
  }
  cout << ans << endl;
}

// --------------------Snippet-Ends--------------------------------

signed main() {
  FASTIO
  p1();
  return 0;
}
