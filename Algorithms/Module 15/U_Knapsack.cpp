#include <bits/stdc++.h>
using namespace std;
int val[25];
int weight[25];
int dp[25][105];

int knapsack(int i, int mx_weight)
{
    if (i < 0 || mx_weight <= 0)
        return 0;

    if (dp[i][mx_weight] != -1)
        return dp[i][mx_weight];

    if (weight[i] <= mx_weight)
    {
        int opt1 = knapsack(i - 1, mx_weight - weight[i]) + val[i];
        int opt2 = knapsack(i - 1, mx_weight);
        dp[i][mx_weight] = max(opt1, opt2);
        return dp[i][mx_weight];
    }
    else
    {
        dp[i][mx_weight] = knapsack(i - 1, mx_weight);
        return dp[i][mx_weight];
    }
}

int main()
{
    int n, mx_weight;
    cin >> n >> mx_weight;
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++)
        cin >> weight[i] >> val[i];

    cout << knapsack(n - 1, mx_weight);

    return 0;
}