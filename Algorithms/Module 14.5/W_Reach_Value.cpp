#include <bits/stdc++.h>
using namespace std;

bool rec(double n)
{
    if (n < 1)
        return false;
    else if (n == 1)
        return true;

    return rec(n / 10) || rec(n / 20);
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long int n;
        cin >> n;

        int res = rec(n);
        if (res)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}