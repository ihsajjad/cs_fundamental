#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, val;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> val;

    int idx = -1;

    for (int i = 0; i < n; i++)
    {

        if (arr[i] == val)
        {
            idx = i;
            break;
        }
    }

    if (idx != -1)
        cout << idx << endl;
    else
        cout << idx << endl;
    return 0;
}