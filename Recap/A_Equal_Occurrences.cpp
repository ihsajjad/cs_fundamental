#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        map<int, int> mp;

        for (int i = 0; i < n; i++)
            mp[arr[i]]++;

        if (mp.size() == 1)
        {
            cout << n << endl;
            continue;
        }

        map<int, int> mp2;

        for (auto item : mp)
            mp2[item.second] = item.first;

        int i = mp.size();
        int occ = INT_MIN;
        for (auto item : mp2)
        {
            occ = max(i * item.first, occ);
            i--;
        }

        if (sizeof(arr) == 0)
            cout << 0 << endl;
        else
            cout << occ << endl;
    }

    return 0;
}