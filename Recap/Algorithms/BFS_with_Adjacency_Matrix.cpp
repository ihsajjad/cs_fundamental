#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_mat;
vector<vector<bool>> vis;
int n, e;

bool is_valid(int i, int j)
{
    if (i < 0 || i > n || j < 0 || j > n)
        return false;
    else
        return true;
}

vector<pair<int, int>> d = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

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

        if (adj_mat[par_i][par_j])
            cout << par_i << " " << par_j << " Ache" << endl;

        for (auto child : d)
        {
            int ci = par_i + child.first;
            int cj = par_j + child.second;

            if (is_valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
            }
        }
    }
}

int main()
{

    cin >> n >> e;

    adj_mat.assign(n + 1, vector<int>(n + 1, 0));
    vis.assign(n + 1, vector<bool>(n + 1, false));

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << adj_mat[i][j] << " ";

        cout << endl;
    }

    bfs(1, 1);

    return 0;
}