#include <bits/stdc++.h>
using namespace std;

bool rec(int n)
{
    if (n == 1 || n == 2)
        return true;
    else if (n < 1)
        return false;

    bool is_pow_of_2 = (n & (n - 1)) == 0;
    if (is_pow_of_2)
        return true;

    return rec(n - 3);
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;

        bool is_possible = rec(n);

        if (is_possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}