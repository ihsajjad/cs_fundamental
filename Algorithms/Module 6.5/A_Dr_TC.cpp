#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int count = 0, ans = 0;
        for (char c : s)
            if (c == '1')
                count++;

        for (char c : s)
            if (c == '1')
                ans += count - 1;
            else
                ans += count + 1;

        cout << ans << endl;
    }

    return 0;
}