#include <bits/stdc++.h>
using namespace std;
string a, b;
int dp[1005][1005];

int lcs(int i, int j)
{
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (a[i] == b[j])
    {
        dp[i][j] = lcs(i - 1, j - 1) + 1;
        return dp[i][j];
    }
    else
    {
        int opt1 = lcs(i, j - 1);
        int opt2 = lcs(i - 1, j);
        dp[i][j] = max(opt1, opt2);
        return dp[i][j];
    }
}

int main()
{
    cin >> a >> b;
    int n = a.size();
    int m = b.size();

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = -1;

    cout << lcs(n - 1, m - 1);
    return 0;
}