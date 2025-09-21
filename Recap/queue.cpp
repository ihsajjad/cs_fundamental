#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    int val;
    while (cin >> val)
        q.push(val);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}