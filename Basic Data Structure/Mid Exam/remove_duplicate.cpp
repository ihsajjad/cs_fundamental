#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> head;
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        head.push_back(val);
        /* code */
    }
    
    for (auto it = head.begin(); it != head.end(); it = it->next)
    {
       cout << it->val << endl;
    }
    
    return 0;
}