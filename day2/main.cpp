#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define int ll
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0);

// --------------------Snippet-Ends--------------------------------

signed main() {
  freopen("input.txt", "r", stdin);
  /* freopen("output.txt", "w", stdout); */

  string line;
  int ans = 0;
  while (getline(cin, line)) {
    map<string, int> mp;
    int mred = 0;
    int mblue = 0;
    int mgreen = 0;
    mp["red"] = 0;
    mp["blue"] = 0;
    mp["green"] = 0;
    string cur = "";
    int i = 5;
    string game_str = "";
    for (; line[i] != ':'; i++) {
      game_str += line[i];
    }
    int game = stoi(game_str);
    i += 2;

    string num = "";
    bool d = false;
    /* cout << game << endl; */
    for (; i < line.size(); i++) {
      if (line[i] == ';') {
        mred = max(mred, mp["red"]);
        mblue = max(mblue, mp["blue"]);
        mgreen = max(mgreen, mp["green"]);
        mp["red"] = 0;
        mp["blue"] = 0;
        mp["green"] = 0;
        num = "";
      }
      if (isdigit(line[i])) {
        num += line[i];
      } else {
        for (auto it = mp.begin(); it != mp.end(); it++) {
          if (line.size() - i < it->first.size()) {
            continue;
          }

          if (line.substr(i, it->first.size()) == it->first) {
            mp[it->first] = stoi(num);
            num = "";
            break;
          }
        }
      }
    }
    mred = max(mred, mp["red"]);
    mblue = max(mblue, mp["blue"]);
    mgreen = max(mgreen, mp["green"]);
    cout << mred << " " << mblue << " " << mgreen << endl;
    ans += mred * mblue * mgreen;
  }
  cout << ans << endl;

  return 0;
}
