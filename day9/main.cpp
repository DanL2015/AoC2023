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

bool all_zeros(vector<int> &arr) {
  for (int &i : arr) {
    if (i != 0)
      return false;
  }
  return true;
}

void p1() {
  string line;
  vector<string> strs;
  int ans = 0;
  while (getline(cin, line)) {
    vector<int> nums;
    vector<int> diff_arr;
    strs = split(line, ' ');
    reverse(strs.begin(), strs.end());
    for (string &s : strs) {
      nums.pb(stol(s));
    }

    vector<int> edge;
    edge.pb(nums.back());

    do {
      for (int i = 1; i < nums.size(); i++) {
        diff_arr.pb(nums[i] - nums[i - 1]);
      }
      nums = diff_arr;
      edge.pb(diff_arr.back());
      diff_arr.clear();
    } while (!all_zeros(nums));

    int cur = 0;
    for (int &i : edge) {
      cout << i << " ";
      cur += i;
    }
    cout << endl;
    cout << cur << endl;
    ans += cur;
  }
  cout << ans << endl;
}

void p2() {
  string line;
  vector<string> strs;
  int ans = 0;
  while (getline(cin, line)) {
    vector<int> nums;
    vector<int> diff_arr;
    strs = split(line, ' ');
    for (string &s : strs) {
      nums.pb(stol(s));
    }

    vector<int> edge;
    edge.pb(nums.front());

    do {
      for (int i = 1; i < nums.size(); i++) {
        diff_arr.pb(nums[i] - nums[i - 1]);
      }
      nums = diff_arr;
      edge.pb(diff_arr.front());
      diff_arr.clear();
    } while (!all_zeros(nums));

    int cur = 0;
    for (int i=0; i<edge.size(); i++) {
      if (i % 2) {
        cur -= edge[i];
      } else {
        cur += edge[i];
      }
    }
    ans += cur;
  }
  cout << ans << endl;
}

// --------------------Snippet-Ends--------------------------------

signed main() {
  FASTIO
  p2();
  return 0;
}
