#include <bits/stdc++.h>
using namespace std;

bool is_pile_of_word(string s1, string s2)
{
    map<char, pair<int, int>> mp;
    int length1 = s1.size(), length2 = s2.size();
    if (length1 != length2)
        return false;
    else if (s1 == s2)
        return true;

    for (int i = 0; i < length1; i++)
    {
        mp[s1[i]].first++;
        mp[s2[i]].second++;
    }

    bool flag = true;
    for (auto child : mp)
    {
        auto p = child.second;
        // cout << child.first << " " << child.second.first << " " << child.second.second << endl;
        if (p.first != p.second)
        {
            flag = false;
            break;
        }
    }

    return flag;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (is_pile_of_word(s1, s2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}