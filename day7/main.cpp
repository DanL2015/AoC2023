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

// --------------------Snippet-Ends--------------------------------
struct h {
  string cards;
  int rank;
  int bid;
};
map<char, int> cmp;

bool comp(h a, h b) {
  if (a.rank != b.rank) {
    return a.rank < b.rank;
  }

  for (int i = 0; i < a.cards.size(); i++) {
    char ac = a.cards[i];
    char bc = b.cards[i];
    if (ac == bc)
      continue;
    return cmp[ac] < cmp[bc];
  }
  return true;
}

void p1() {
  vector<string> strs;
  string line;
  vector<h> hands;
  cmp['A'] = 1;
  cmp['K'] = 2;
  cmp['Q'] = 3;
  cmp['J'] = 4;
  cmp['T'] = 5;
  cmp['9'] = 6;
  cmp['8'] = 7;
  cmp['7'] = 8;
  cmp['6'] = 9;
  cmp['5'] = 10;
  cmp['4'] = 11;
  cmp['3'] = 12;
  cmp['2'] = 13;

  while (getline(cin, line)) {
    strs = split(line, ' ');
    map<char, int> hand;
    h cur;
    cur.bid = stoi(strs[1]);
    cur.cards = strs[0];
    for (char &c : strs[0]) {
      hand[c]++;
    }

    vector<int> nums;
    for (auto it = hand.begin(); it != hand.end(); it++) {
      nums.pb(it->second);
    }

    sort(nums.begin(), nums.end(), greater<int>());

    if (nums[0] == 5) {
      cur.rank = 1;
    } else if (nums[0] == 4) {
      cur.rank = 2;
    } else if (nums[0] == 3 && nums[1] == 2) {
      cur.rank = 3;
    } else if (nums[0] == 3) {
      cur.rank = 4;
    } else if (nums[0] == 2 && nums[1] == 2) {
      cur.rank = 5;
    } else if (nums[0] == 2) {
      cur.rank = 6;
    } else {
      cur.rank = 7;
    }

    hands.pb(cur);
  }

  sort(hands.begin(), hands.end(), comp);
  int ans = 0;
  for (int i = 0; i < hands.size(); i++) {
    ans += hands[i].bid * (hands.size() - i);
  }
  cout << ans << endl;
}

void p2() {
  vector<string> strs;
  string line;
  vector<h> hands;
  cmp['A'] = 1;
  cmp['K'] = 2;
  cmp['Q'] = 3;
  cmp['T'] = 4;
  cmp['9'] = 5;
  cmp['8'] = 6;
  cmp['7'] = 7;
  cmp['6'] = 8;
  cmp['5'] = 9;
  cmp['4'] = 10;
  cmp['3'] = 11;
  cmp['2'] = 12;
  cmp['J'] = 13;
  while (getline(cin, line)) {
    strs = split(line, ' ');
    map<char, int> hand;
    h cur;
    cur.bid = stoi(strs[1]);
    cur.cards = strs[0];
    for (char &c : strs[0]) {
      hand[c]++;
    }

    vector<int> nums;
    int jokers = 0;
    for (auto it = hand.begin(); it != hand.end(); it++) {
      if (it->first == 'J') {
        jokers = it->second;
      } else {
        nums.pb(it->second);
      }
    }

    sort(nums.begin(), nums.end(), greater<int>());

    if (jokers == 5) {
      cur.rank = 1;
    }
    else if (nums[0] + jokers == 5) {
      cur.rank = 1;
    } else if (nums[0] + jokers == 4) {
      cur.rank = 2;
    } else if (nums[0] + jokers == 3 && nums.size() > 1 && nums[1] == 2) {
      cur.rank = 3;
    } else if (nums[0] + jokers == 3) {
      cur.rank = 4;
    } else if (nums[0] + jokers == 2 && nums.size() > 1 && nums[1] == 2) {
      cur.rank = 5;
    } else if (nums[0] + jokers == 2) {
      cur.rank = 6;
    } else {
      cur.rank = 7;
    }

    hands.pb(cur);
  }

  sort(hands.begin(), hands.end(), comp);
  int ans = 0;
  for (int i = 0; i < hands.size(); i++) {
    ans += hands[i].bid * (hands.size() - i);
  }
  cout << ans << endl;
}

signed main() {
  FASTIO
  p2();
  return 0;
}
