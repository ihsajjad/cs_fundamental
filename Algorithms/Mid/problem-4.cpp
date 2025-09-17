#include <bits/stdc++.h>
using namespace std;

int n, m, si, sj, di, dj, total_path = INT_MAX;
char adj_mat[1005][1005];
bool vis[1005][1005];
pair<int, int> parent[1005][1005];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool is_valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    else
        return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while (!q.empty())
    {
        auto par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if (is_valid(ci, cj) && !vis[ci][cj] && adj_mat[ci][cj] != '#')
            {
                parent[ci][cj] = par;
                vis[ci][cj] = true;
                q.push({ci, cj});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> adj_mat[i][j];
            if (adj_mat[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            else if (adj_mat[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }

    bfs(si, sj);

    int node_i = di, node_j = dj;
    while (adj_mat[node_i][node_j] != 'R' && vis[di][dj])
    {
        auto par = parent[node_i][node_j];
        node_i = par.first;
        node_j = par.second;

        if (adj_mat[node_i][node_j] == '.')
            adj_mat[node_i][node_j] = 'X';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << adj_mat[i][j];
        cout << endl;
    }

    return 0;
}
