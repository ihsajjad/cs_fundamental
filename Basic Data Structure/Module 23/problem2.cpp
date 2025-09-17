#include <bits/stdc++.h>

using namespace std;

class MyPair
{
public:
    string name;
    int val;

    MyPair(string name, int val)
    {
        this->name = name;
        this->val = val;
    }
};

class cmp
{
public:
    bool operator()(MyPair l, MyPair r)
    {
        if (l.name == r.name)
            return l.val < r.val;
        else
            return l.name > r.name;
    }
};

int main()
{

    int n;
    cin >> n;
    priority_queue<MyPair, vector<MyPair>, cmp> pq;

    while (n--)
    {
        string name;
        int val;
        cin >> name >> val;
        MyPair myP(name, val);
        pq.push(myP);
    }

    while (!pq.empty())
    {
        MyPair pr = pq.top();
        pq.pop();
        cout << pr.name << " " << pr.val << endl;
    }
    return 0;
}
