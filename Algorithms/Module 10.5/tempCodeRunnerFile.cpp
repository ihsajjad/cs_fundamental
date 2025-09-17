#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;

        if (s.size() == 1)
        {
            s.push_back(s[0] + 1);
            cout << s << endl;
            continue;
        }

        int is_changed = false;
        string head, tail;
        for (int i = 0, j = 1; i < s.size() && j < s.size(); i++, j++)
        {
            if (s[i] == s[j] && !is_changed)
            {
                tail = s.substr(j);
                s[j] = s[i] + 1;
                head = s.substr(0, j + 1);
                is_changed = true;
                break;
            }
        }

        if (is_changed)
            s = head + tail;

        cout << s << endl;
    }

    return 0;
}