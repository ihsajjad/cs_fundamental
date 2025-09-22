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

Node *input_binary_tree()
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

bool is_special(Node *root)
{
    if (!root)
        return true;

    if ((!root->left && root->right) || (root->left && !root->right))
    {
        return false;
    }

    bool l = is_special(root->left);
    bool r = is_special(root->right);

    return l && r;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        Node *root = input_binary_tree();

        if (is_special(root))
            cout << "Special" << endl;
        else
            cout << "Not Special" << endl;
    }

    return 0;
}