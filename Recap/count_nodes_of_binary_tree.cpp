#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_binary_tree()
{
    Node *root = NULL;

    int val;
    cin >> val;
    if (val != -1)
        root = new Node(val);

    queue<Node *> q;

    if (root)
        q.push(root);

    while (!q.empty())
    {
        Node *par = q.front();
        q.pop();

        Node *myLeft = NULL, *myRight = NULL;
        int l, r;
        cin >> l >> r;

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

int count_nodes(Node *root)
{
    if (!root)
        return 0;

    int total_left = count_nodes(root->left);
    int total_right = count_nodes(root->right);

    return total_left + total_right + 1;
}

int count_leap(Node *root)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return 1;
    else
    {
        int l = count_leap(root->left);
        int r = count_leap(root->right);
        return l + r;
    }
}

int main()
{
    Node *root = input_binary_tree();

    cout << "Nodes = " << count_nodes(root) << endl;
    cout << "Leaps = " << count_leap(root) << endl;
    return 0;
}