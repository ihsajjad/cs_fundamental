#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    int val;
    while (cin >> val)
        st.push(val);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}