#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    while (n--)
    {
        int val;
        cin >> val;
        pq.push(val);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 0)
        {
            int x;
            cin >> x;

            pq.push(x);
            cout << pq.top() << endl;
        }
        else if (cmd == 1)
        {
            if (pq.empty())
                cout << "Empty" << endl;
            else
            {
                cout << pq.top() << endl;
            }
        }
        else
        {
            if (!pq.empty())
                pq.pop();

            if (pq.empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                cout << pq.top() << endl;
            }
        }
    }

    return 0;
}
