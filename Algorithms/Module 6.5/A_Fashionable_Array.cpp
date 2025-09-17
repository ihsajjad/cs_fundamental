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

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n);
        int mn = arr[0];
        int mx = arr[n - 1];

        if (mn % 2 == mx % 2)
        {
            cout << 0 << endl;
            continue;
        }

        int i = 0, count = 0;
        while (arr[i] % 2 != mx % 2)
        {
            i++;
            count++;
        }

        int j = n - 1, count2 = 0;
        while (mn % 2 != arr[j] % 2)
        {
            j--;
            count2++;
        }

        cout << min(count, count2) << endl;
    }

    return 0;
}