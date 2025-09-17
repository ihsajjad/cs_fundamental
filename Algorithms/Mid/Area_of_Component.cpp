#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0;
char adj_mat[1005][1005];
bool vis[1005][1005];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool is_valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    else
        return true;
}

void dfs(int si, int sj)
{

    vis[si][sj] = true;
    cnt++;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (is_valid(ci, cj) && !vis[ci][cj] && adj_mat[ci][cj] == '.')
            dfs(ci, cj);
    }
}

int main()
{
    cin >> n >> m;
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> adj_mat[i][j];

    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && adj_mat[i][j] == '.')
            {
                cnt = 0;
                dfs(i, j);
                mn = min(cnt, mn);
            }
        }

    if (mn != INT_MAX)
        cout << mn;
    else
        cout << -1;

    return 0;
}
