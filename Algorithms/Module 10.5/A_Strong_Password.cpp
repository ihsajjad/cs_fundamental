#include <bits/stdc++.h>
using namespace std;

char get_char(int i)
{
    if (i == 122)
        return i - 1;
    else
        return i + 1;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;

        int is_changed = false;
        string head, tail;
        for (int i = 0, j = 1; i < s.size() && j < s.size(); i++, j++)
        {
            if (s[i] == s[j] && !is_changed)
            {
                tail = s.substr(j);
                s[j] = get_char(s[i]);
                head = s.substr(0, j + 1);
                is_changed = true;
                break;
            }
        }

        if (is_changed)
            s = head + tail;
        else
            s.push_back(get_char(s[s.size() - 1]));

        cout
            << s << endl;
    }

    return 0;
}