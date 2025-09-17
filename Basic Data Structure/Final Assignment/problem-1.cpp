#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        st.push(val);
    }

    queue<int> q;
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        q.push(val);
    }

    if (st.size() != q.size())
    {
        cout << "NO" << endl;
        return 0;
    }

    bool flag = true;
    while (!st.empty())
    {
        if (st.top() != q.front())
        {
            flag = false;
        }
        st.pop();
        q.pop();
    }

    if (flag)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}