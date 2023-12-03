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

int is_adj(vector<string> &schematic, int r, int c)
{
    vector<vector<bool>> vis(3, vector<bool>(3, false));
    int num = 0;
    int ans = -1;
    for (int i = 0; i < 8; i++)
    {
        int cr = r + dx[i];
        int cc = c + dy[i];
        if (cr < 0 || cc < 0 || cr >= schematic.size() || cc >= schematic[cr].size())
            continue;
        if (vis[dx[i] + 1][dy[i] + 1])
            continue;
        if (isdigit(schematic[cr][cc]))
        {
            int k = cc;
            string cur = "";
            while (k >= 0 && isdigit(schematic[cr][k]))
            {
                k--;
            }
            k++;
            while (k < schematic[cr].size() && isdigit(schematic[cr][k]))
            {
                if (k - c < 3 && k-c >= 0)
                {
                    vis[dx[i] + 1][k - c] = true;
                }
                cur += schematic[cr][k];
                k++;
            }
            if (ans == -1)
            {
                ans = stoi(cur);
            }
            else
            {
                ans *= stoi(cur);
            }
            num++;
        }
    }
    if (num == 2)
    {
        return ans;
    }
    return -1;
}

signed main()
{
    // FASTIO
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
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
            if (schematic[i][j] == '*')
            {
                int res = is_adj(schematic, i, j);
                if (res != -1)
                {
                    ans += res;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}