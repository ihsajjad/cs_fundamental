#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    while (q--)
    {
        int q_val;
        cin >> q_val;
        bool flag = false;
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (arr[m] == q_val)
            {
                flag = true;
                break;
            }
            else if (arr[m] < q_val)
                l = m + 1;
            else
                r = m - 1;
        }

        if (flag)
            cout << "found" << endl;
        else
            cout << "not found" << endl;
    }

    return 0;
}