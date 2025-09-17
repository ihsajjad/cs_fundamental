#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long int> dp(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        if (i <= 0)
        {
            dp[i] = 0;
            continue;
        }
        else if (i == 1)
        {
            dp[i] = 1;
            continue;
        }
        else if (i == 2)
        {
            dp[i] = 1;
            continue;
        }
        else if (i == 3)
        {
            dp[i] = 2;
            continue;
        }

        int t0 = i - 4;
        int t1 = i - 3;
        int t2 = i - 2;
        int t3 = i - 1;

        dp[i] = dp[t0] + dp[t1] + dp[t2] + dp[t3];
    }

    cout << dp[n];

    return 0;
}