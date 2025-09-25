#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    vector<int> v;

    for (int i = 0; i < q; i++)
    {
        int cmd, val;
        cin >> cmd;

        if (cmd == 1)
        {
            cin >> val;
            v.push_back(val);
        }
        else if (cmd == 2)
        {
            if (v.empty())
                cout << "empty\n";
            else
            {
                int mn = INT_MAX;

                for (int child : v)
                    if (child < mn)
                        mn = min(child, mn);

                v.erase(remove(v.begin(), v.end(), mn), v.end());

                cout << mn << '\n';
            }
        }
    }

    return 0;
}