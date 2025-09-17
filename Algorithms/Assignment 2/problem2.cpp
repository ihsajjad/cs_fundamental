#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> adj_mat;

int main()
{
    int n, e;
    cin >> n >> e;

    adj_mat.assign(n + 1, vector<long long int>(n + 1, LLONG_MAX));
    for (int i = 0; i <= n; i++)
        adj_mat[i][i] = 0;

    while (e--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;

        adj_mat[a][b] = min(adj_mat[a][b], c);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj_mat[i][k] == LLONG_MAX || adj_mat[k][j] == LLONG_MAX)
                    continue;

                if (adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int src, dst;
        cin >> src >> dst;

        if (adj_mat[src][dst] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << adj_mat[src][dst] << endl;
    }

    return 0;
}