#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    queue<string> q;

    while(n--)
    {
        string cmd;
        cin >> cmd;
        
        if(cmd == "ARRIVE")
        {
            string p;
            cin >> p;
            q.push(p);
        }
        else if(cmd == "SERVE")
        {
            if(q.empty()) cout << "No patients" << endl;
            else q.pop();
        }
        else if(cmd == "FIRST")
        {
            if(q.empty()) cout << "No patients" << endl;
            else cout << q.front() << endl;
        }
        else if(cmd == "LAST")
        {
            if(q.empty()) cout << "No patients" << endl;
            else cout << q.back() << endl;
        }
        else if(cmd == "COUNT")
        {
            if(q.empty()) cout << "No patients" << endl;
            else cout << q.size() << endl;
        }
        else if(cmd == "SHOW")
        {
            queue<string> q2 = q;
            while(!q2.empty())
            {
                cout << q2.front() << " ";
                q2.pop();
            }
            cout << endl;
        }

    }
    return 0;
}