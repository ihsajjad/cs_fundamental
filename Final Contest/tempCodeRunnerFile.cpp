#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int ln;
        cin >> ln;
        vector<char> str(ln);
        for (int i = 0; i < ln; i++)
        {
            cin >> str[i];
        }

        int i = 0;
        int j = 1;
        while (j < ln)
        {
            if (str[i] == str[j])
            {
                for (int k = i, l = j; k < ln; k++, l++)
                {
                    if (str[l + 1])
                        str[k] = str[l + 1];
                }
                str.erase(str.end() - 2, str.end());
                i--;
                j--;
            }
            else
            {
                i++;
                j++;
            }
        }

        cout << str.size() << '\n';
    }

    return 0;
}