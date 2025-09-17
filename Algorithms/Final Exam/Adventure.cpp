#include <bits/stdc++.h>
using namespace std;
int val[1005];
int weight[1005];
long long int dp[1005][1005];

int rec(int i, int mx_weight)
{
    if (i < 0 || mx_weight <= 0)
        return 0;

    if (dp[i][mx_weight] != -1)
        return dp[i][mx_weight];

    if (weight[i] <= mx_weight)
    {
        int opt1 = rec(i - 1, mx_weight - weight[i]) + val[i];
        int opt2 = rec(i - 1, mx_weight);
        dp[i][mx_weight] = max(opt1, opt2);

        return dp[i][mx_weight];
    }
    else
    {
        dp[i][mx_weight] = rec(i - 1, mx_weight);
        return dp[i][mx_weight];
    }
}

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, mx_weight;
        cin >> n >> mx_weight;

        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; i++)
            cin >> weight[i];
        for (int i = 0; i < n; i++)
            cin >> val[i];

        cout << rec(n - 1, mx_weight) << endl;
    }

    return 0;
}