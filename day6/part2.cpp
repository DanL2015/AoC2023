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

int get_dist(int time, int speed) {
  return speed * (time - speed);
}

signed main() {
  FASTIO
  int time;
  int dist;
  string line;
  vector<string> strs;

  getline(cin, line);
  strs = split(line, ' ');
  time = stol(strs[1]);

  getline(cin, line);
  strs = split(line, ' ');
  dist = stol(strs[1]);
  
  int l = 0;
  int r = time;

  //get middle
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (get_dist(time, mid) < get_dist(time, mid - 1)) {
      r = mid - 1;
    }
    else if (get_dist(time, mid) > get_dist(time, mid - 1)) {
      l = mid;
    }
  }

  int center = l;
  l = 0;
  r = center;
  //get lower bound, only check left of center
  while (l < r) {
    int mid = (l + r) / 2;
    if (get_dist(time, mid) > dist) {
      r = mid;
    } else if (get_dist(time, mid) <= dist) {
      l = mid + 1;
    }
  }
  int lower = l;

  l = center;
  r = time;
  //get upper bound
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (get_dist(time, mid) > dist) {
      l = mid;
    } else if (get_dist(time, mid) <= dist) {
      r = mid - 1;
    }
  }
  int upper = r;
  cout << upper - lower + 1 << endl;
  return 0;
}
