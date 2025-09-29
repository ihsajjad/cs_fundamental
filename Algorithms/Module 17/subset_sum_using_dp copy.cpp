#include <bits/stdc++.h>
using namespace std;
int arr[1005];
vector<vector<int>> dp(1005, vector<int>(1005, -1));

bool subset_sum(int i, int sum)
{
    if (i < 0)
        return sum == 0;

    if (dp[i][sum] != -1)
        return dp[i][sum];

    if (arr[i] <= sum)
    {
        bool opt1 = subset_sum(i - 1, sum - arr[i]);
        bool opt2 = subset_sum(i - 1, sum);
        dp[i][sum] = opt1 || opt2;
        return dp[i][sum];
    }
    else
        dp[i][sum] = subset_sum(i - 1, sum);
    return dp[i][sum];
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum;
    cin >> sum;

    if (subset_sum(n - 1, sum))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}