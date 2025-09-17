#include <bits/stdc++.h>
using namespace std;
vector<int> dp;

int rec(int n)
{
    if (n < 0)
        return 0;
    if (n == 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = rec(n - 4) + rec(n - 3) + rec(n - 2) + rec(n - 1);

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    dp.assign(n + 1, -1);

    cout << rec(n);
    return 0;
}