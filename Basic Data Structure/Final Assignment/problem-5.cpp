#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        stack<char> st;
        for (char c : s)
        {
            if (st.empty())
                st.push(c);
            else
            {
                if (c == '1' && st.top() == '0')
                {
                    if (!st.empty())
                        st.pop();
                }
                else
                    st.push(c);
            }
        }
        
        if (st.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}