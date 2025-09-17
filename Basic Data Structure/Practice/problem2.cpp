#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left = NULL;
    Node *right = NULL;

    Node(int val)
    {
        this->val = val;
    }
};

Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val != -1)
        root = new Node(val);
    else
        root = NULL;

    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        Node *myLeft = NULL, *myRight = NULL;
        int l, r;
        cin >> l >> r;
        if (l != -1)
            myLeft = new Node(l);
        if (r != -1)
            myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }

    return root;
}

int main()
{
    Node *root = input_tree();
    set<pair<int, int>> st;
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        if (!p->left && !p->right)
        {
            
        }

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }

    return 0;
}