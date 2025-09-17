#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int a, b;
        cin >> a >> b;

        int count = min(a, b / 2) * 3;

        // while (a >= 1 && b >= 2)
        // {
        //     a--;
        //     b -= 2;
        //     count += 3;
        // }
        // cout << count << endl;

        cout << count << endl;
    }

    return 0;
}