#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n;
    cin >> n;

    map<long long int, pair<long long int, long long int>> mp;

    for (long long int i = 1; i <= n; i++)
    {
        long long int val;
        cin >> val;

        if (!mp[val].first)
            mp[val].first = i; // first index
        mp[val].second = i; // last index
    }

    for (auto child : mp)
        cout << child.first << " " << child.second.first << " " << child.second.second << '\n';

    return 0;
}