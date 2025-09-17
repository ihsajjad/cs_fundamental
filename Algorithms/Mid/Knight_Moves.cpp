#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> d = {{-2, 1}, {1, -2}, {-2, -1}, {-1, -2}, {-1, 2}, {2, -1}, {1, 2}, {2, 1}};

bool is_valid(int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    else
        return true;
}

void bfs(int si, int sj, int n, int m, vector<vector<bool>> &vis, vector<vector<int>> &level)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        auto par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;
        int pl = level[par_i][par_j];
        for (int i = 0; i < 8; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if (is_valid(ci, cj, n, m) && !vis[ci][cj])
            {
                level[ci][cj] = pl + 1;
                vis[ci][cj] = true;
                q.push({ci, cj});
            }
        }
    }
}

int main()
{
    int t_case;
    cin >> t_case;

    while (t_case--)
    {
        int n, m, si, sj, di, dj;
        cin >> n >> m >> si >> sj >> di >> dj;

        if (si == di && sj == dj)
        {
            cout << 0 << endl;
            continue;
        }

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> level(n, vector<int>(m, -1));

        bfs(si, sj, n, m, vis, level);

        cout << level[di][dj] << endl;
    }

    return 0;
}
