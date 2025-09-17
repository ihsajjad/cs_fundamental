#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<string> &logs)
{
    stack<string> st;
    for (string log : logs)
    {
        cout << log << endl;
        if (log == "./")
            ;
        else if (log == "../")
        {
            if (!st.empty())
                st.pop();
        }
        else
            st.push(log);
    }
    return st.size();
}

int main()
{
    vector<string> v = {"./", "../", "./"};

    cout << minOperations(v) << endl;
    ;
    return 0;
}