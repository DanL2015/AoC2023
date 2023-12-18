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
  string line;
  getline(cin, line);
  vector<string> codes = split(line, ',');

  int ans = 0;
  for (string &s : codes) {
    int cur = 0;
    for (char &c : s) {
      cur += c;
      cur *= 17;
      cur %= 256;
    }
    ans += cur;
  }
  cout << ans << endl;
}

void p2() {
  string line;
  getline(cin, line);
  vector<string> codes = split(line, ',');
  vector<vector<pair<string, int>>> boxes(256, vector<pair<string, int>>());

  for (string &s : codes) {
    // get the label
    int ind = 0;
    while (s[ind] != '-' && s[ind] != '=' && ind < s.size())
      ind++;
    string label = s.substr(0, ind);

    int hash = 0;
    for (char &c : label) {
      hash += c;
      hash *= 17;
      hash %= 256;
    }

    if (s[ind] == '=') {
      string f_str = "";
      ind++;
      while (ind < s.size() && isdigit(s[ind]))
        f_str += s[ind++];
      int f = stoi(f_str);
      bool found = false;
      for (int i = 0; i < boxes[hash].size(); i++) {
        if (boxes[hash][i].first == label) {
          boxes[hash][i].second = f;
          found = true;
        }
      }
      if (!found) {
        boxes[hash].pb({label, f});
      }
    }
    else if (s[ind] == '-') {
      for (int i=0; i<boxes[hash].size(); i++) {
        if (boxes[hash][i].first == label) {
          boxes[hash].erase(boxes[hash].begin() + i);
          break;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < boxes.size(); i++) {
    for (int j = 0; j < boxes[i].size(); j++) {
      ans += (i + 1) * (j + 1) * boxes[i][j].second;
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
