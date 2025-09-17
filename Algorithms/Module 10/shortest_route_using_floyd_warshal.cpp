#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e, q;
    cin >> n >> e >> q;

    long long int adj_mat[n + 2][n + 2];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = LONG_LONG_MAX;

    while (e--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;

        adj_mat[a][b] = min(adj_mat[a][b], c);
        adj_mat[b][a] = min(adj_mat[a][b], c);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (adj_mat[i][k] == LONG_LONG_MAX || adj_mat[k][j] == LONG_LONG_MAX)
                    continue;

                if (adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                    adj_mat[j][i] = adj_mat[i][k] + adj_mat[k][j];
                }
            }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (adj_mat[a][b] != LONG_LONG_MAX)
            cout << adj_mat[a][b] << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}