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
        stack<char> st;

        for (int i = 0; i < ln; i++)
        {
            char x;
            cin >> x;
            if (st.empty())
                st.push(x);
            else if (st.top() == x)
                st.pop();
            else
                st.push(x);
        }

        cout << st.size() << '\n';
    }

    return 0;
}
