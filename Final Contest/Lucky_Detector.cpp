#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;

    bool flag = false;
    while (n != 0)
    {
        int d = n % 10;
        if (d == 7)
            flag = true;
        n = n / 10;
    }

    if (flag)
        cout << "Lucky\n";
    else
        cout << "Not Lucky\n";

    return 0;
}