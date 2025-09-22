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

Node *input_binary()
{
    int val;
    cin >> val;

    Node *root = NULL;

    if (val != -1)
        root = new Node(val);

    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        Node *par = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node *myLeft = NULL, *myRight = NULL;

        if (l != -1)
            myLeft = new Node(l);
        if (r != -1)
            myRight = new Node(r);

        par->left = myLeft;
        par->right = myRight;

        if (par->left)
            q.push(par->left);
        if (par->right)
            q.push(par->right);
    }

    return root;
}

int mx = INT_MIN;

void reverse(Node *root)
{
    if (!root)
        return;

    reverse(root->left);
    reverse(root->right);
    cout << root->val << " ";
}

int main()
{
    Node *root = input_binary();
    reverse(root);

    return 0;
}