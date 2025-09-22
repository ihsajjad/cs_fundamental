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

int max_diameter(Node *root)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return 1;

    int l = max_diameter(root->left);
    int r = max_diameter(root->right);
    int d = l + r;
    mx = max(mx, d);

    return mx;
}

int main()
{
    Node *root = input_binary();

    cout << max_diameter(root) << endl;
    return 0;
}