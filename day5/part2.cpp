#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define int ll
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0), cin.tie(0);

// --------------------Snippet-Ends--------------------------------

struct sd {
  int st;
  int ed;
  bool md;
};

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

bool comp(sd a, sd b) { return a.st < b.st; }

signed main() {
  FASTIO

  string line;
  getline(cin, line);
  vector<string> seed_str = split(line, ' ');
  seed_str.erase(seed_str.begin());
  vector<sd> seed;
  for (int i = 0; i <= seed_str.size() / 2; i += 2) {
    int st = stol(seed_str[i]);
    int ed = st + stol(seed_str[i + 1]);
    seed.push_back({st, ed, false});
  }
  getline(cin, line);

  for (int k = 0; k < 7; k++) {
    getline(cin, line);
    while (getline(cin, line) && line != "") {
      vector<string> i = split(line, ' ');
      int dest = stol(i[0]);
      int source = stol(i[1]);
      int range = stol(i[2]);
      int end = source + range;

      for (int j = 0; j < seed.size(); j++) {
        if (seed[j].md) continue;
        if (seed[j].st >= source && seed[j].ed <= end) {
          seed[j].st = dest + (seed[j].st - source);
          seed[j].ed = dest + (seed[j].ed - source);
          seed[j].md = true;

        } else if (seed[j].st < end && end < seed[j].ed) {
          if (seed[j].st != end)
            seed.pb({seed[j].st, end, false});
          if (seed[j].ed != end)
            seed.pb({end, seed[j].ed, false});
          seed.erase(seed.begin() + j);
          j--;
        } else if (seed[j].st <= source && source < seed[j].ed) {
          if (seed[j].st != source)
            seed.pb({seed[j].st, source, false});
          if (seed[j].ed != source)
            seed.pb({source, seed[j].ed, false});
          seed.erase(seed.begin() + j);
          j--;
        }
      }
    }
    for (int j = 0; j < seed.size(); j++) {
      seed[j].md = false;
    }
  }

  sort(seed.begin(), seed.end(), comp);
  cout << seed[0].st << endl;

  return 0;
}
