#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long int pre_sum[n];
    pre_sum[0] = arr[0];
    for (int i = 1; i < n; i++)
        pre_sum[i] = pre_sum[i - 1] + arr[i];

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
            cout << pre_sum[b - 1] << endl;
        else
            cout << (pre_sum[b - 1] - pre_sum[a - 2]) << endl;
    }

    return 0;
}