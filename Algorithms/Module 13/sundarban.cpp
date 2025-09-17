#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj_mat;
vector<vector<int>> level;
vector<vector<bool>> vis;

vector<pair<int, int>> d = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool is_valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= n)
        return false;
    else
        return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    level[si][sj] = 0;

    while (!q.empty())
    {
        auto par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        int par_l = level[par_i][par_j];

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if (is_valid(ci, cj) && !vis[ci][cj] && adj_mat[ci][cj] != 'T')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = par_l + 1;
            }
        }
    }
}

int main()
{
    int si, sj, di, dj;

    while (cin >> n)
    {
        adj_mat.assign(n, vector<int>(n, -1));
        level.assign(n, vector<int>(n, -1));
        vis.assign(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> adj_mat[i][j];
                if (adj_mat[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                else if (adj_mat[i][j] == 'E')
                {
                    di = i;
                    dj = j;
                }
            }

        cout << level[di][dj] << endl;
    }

    return 0;
}