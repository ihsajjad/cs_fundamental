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

        int left = 0, right = n - 1;
        long long int max_area = 0;
        int idx_a = 0, idx_b = 0;
        int min_h = -1;
        while (left < right)
        {
            int minH = min(arr[left], arr[right]);
            int area = minH * (right - left);

            if (minH > min_h || (minH == min_h && area > max_area))
            {
                min_h = minH;
                max_area = area;
                idx_a = left;
                idx_b = right;
            }

            if (arr[left] < arr[right])
                left++;
            else
                right--;
        }

        cout << idx_a << " " << idx_b << endl;
    }

    return 0;
}