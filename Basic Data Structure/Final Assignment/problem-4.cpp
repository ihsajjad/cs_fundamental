#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    queue<string> st;
    for (int i = 0; i < t; i++)
    {
        int sign;
        cin >> sign;

        if (sign == 0)
        {
            string name;
            cin >> name;
            st.push(name);
        }
        else
        {
            if (st.empty())
                cout << "Invalid" << endl;
            else
            {
                cout << st.front() << endl;
                st.pop();
            }
        }
    }

    return 0;
}