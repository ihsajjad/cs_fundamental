#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next = NULL;
    Node *prev = NULL;
    Node(int val)
    {
        this->val = val;
    }
};

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void delete_at_head(Node *&head, Node *&tail)
{
    if (head == tail)
    {
        head = NULL;
        tail = NULL;
        return;
    }

    Node *deltenode = head;
    head = head->next;
    head->prev = NULL;
    delete deltenode;
}

void delete_at_tail(Node *&head, Node *&tail)
{
    if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    tail->prev->next = tail->next;
    tail = tail->prev;
}

class MyStack
{
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

public:
    void push(int val)
    {
        insert_at_tail(head, tail, val);
        sz++;
    }
    void pop()
    {
        delete_at_tail(head, tail);
        sz--;
    }
    int top()
    {
        return tail->val;
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        return sz == 0;
    }
};

class MyQueue
{
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

public:
    void push(int val)
    {
        insert_at_tail(head, tail, val);
        sz++;
    }
    void pop()
    {
        delete_at_head(head, tail);
        sz--;
    }
    int front()
    {
        return head->val;
    }
    int back()
    {
        return tail->val;
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        return sz == 0;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    // if the length is not equal
    if (n != m)
    {
        cout << "NO" << endl;
        return 0;
    }

    MyStack st;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        st.push(val);
    }

    MyQueue q;
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        q.push(val);
    }

    while (!q.empty())
    {
        if (st.top() != q.front())
        {
            cout << "NO";
            return 0;
        }
        q.pop();
        st.pop();
    }

    cout << "YES";

    return 0;
}