#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long int a, b;
        cin >> a >> b;

        long long int mn = min(a, b);
        long long int mx = max(a, b);

        long long int sum1 = ((mn - 1) * mn) / 2;
        long long int sum2 = (mx * (mx + 1) / 2);

        cout << sum2 - sum1 << endl;
    }

    return 0;
}