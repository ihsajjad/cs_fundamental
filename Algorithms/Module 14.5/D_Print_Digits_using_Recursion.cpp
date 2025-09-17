#include <bits/stdc++.h>
using namespace std;

void rec(int n)
{
    if (n == 0)
    {
        cout << 0 << " ";
        return;
    }
    int ans = n % 10;
    if (n / 10)
        rec(n / 10);

    cout << ans << " ";
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        rec(n);
        cout << endl;
    }

    return 0;
}