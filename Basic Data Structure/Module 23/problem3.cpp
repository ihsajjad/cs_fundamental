#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string s;
        getline(cin, s);

        map<string, int> mp;
        pair<string, int> max = {"", INT_MIN};

        stringstream ss(s);
        string word;

        while (ss >> word)
        {
            mp[word]++;
            if (max.second < mp[word])
            {
                max = {word, mp[word]};
            }
        }

        cout << max.first << " " << max.second << endl;
    }

    return 0;
}
