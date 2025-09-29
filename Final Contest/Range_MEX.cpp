#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, q;
    cin >> n >> q;
    vector<int> arr(n);

    for (long long int i = 1; i <= n; i++)
        cin >> arr[i];

    while (q--)
    {
        long long int l, r;
        cin >> l >> r;

        vector<int> sub_arr(arr.begin() + l, arr.begin() + r + 1);
        sort(sub_arr.begin(), sub_arr.end());

        long long int mex = 0;
        for (long long int i : sub_arr)
            if (mex == i)
                mex++;

        cout << mex << '\n';
    }

    return 0;
}