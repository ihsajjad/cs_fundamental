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

void level_order_traversal(Node *root)
{
    if (!root)
    {
        cout << "NO Tree";
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *par = q.front();
        q.pop();

        cout << par->val << " ";

        if (par->left)
            q.push(par->left);
        if (par->right)
            q.push(par->right);
    }
}

int main()
{

    Node *root = input_binary_tree();

    level_order_traversal(root);

    return 0;
}