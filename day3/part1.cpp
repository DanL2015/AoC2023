#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define int ll
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0), cin.tie(0);

// --------------------Snippet-Ends--------------------------------
int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 1, 0, -1, 1, 0, -1};

bool is_adj(vector<string> &schematic, int r, int c)
{
    bool res = false;
    for (int i = 0; i < 8; i++)
    {
        int cr = r + dx[i];
        int cc = c + dy[i];
        if (cr < 0 || cc < 0 || cr >= schematic.size() || cc >= schematic[cr].size())
            continue;
        if (schematic[cr][cc] != '.' && !isdigit(schematic[cr][cc])) {
            res = true;
            return res;
        }
    }

    return res;
}

signed main()
{
    // FASTIO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<string> schematic;
    string line;
    while (getline(cin, line))
    {
        schematic.pb(line);
    }

    int ans = 0;

    for (int i = 0; i < schematic.size(); i++)
    {
        for (int j = 0; j < schematic[i].size(); j++)
        {
            if (isdigit(schematic[i][j]) && is_adj(schematic, i, j))
            {
                int k = j;
                // find the start of the digit
                while (k >= 0 && isdigit(schematic[i][k]))
                {
                    k--;
                }
                k++;
                string cur = "";
                while (k < schematic[i].size() && isdigit(schematic[i][k]))
                {
                    cur += schematic[i][k];
                    k++;
                }
                if (cur != "")
                {
                    ans += stoi(cur);
                }
                j = k;
            }
        }
    }
    cout << ans << endl;

    return 0;
}