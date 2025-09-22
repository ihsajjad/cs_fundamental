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

bool find_node(Node *root, int val)
{
    if (!root)
        return false;

    if (root->val == val)
        return true;

    bool l = find_node(root->left, val);
    bool r = find_node(root->right, val);

    return l || r;
}

void print_preorder(Node *root)
{
    if (!root)
        return;

    cout << root->val << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}

int main()
{
    Node *root = input_binary_tree();

    int val;
    cin >> val;

    if (find_node(root, val))
        cout << "Yes " << endl;
    else
        cout << "No "<< val << endl;

    return 0;
}