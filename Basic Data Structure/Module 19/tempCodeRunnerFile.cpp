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
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *myLeft, *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);
        if (r == -1)
            myRight = NULL;
        else
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

void print_left(Node *root)
{
    if (!root)
        return;

    if (root->left)
        print_left(root->left);
    else
        print_left(root->right);
    cout << root->val << " ";
}

void print_right(Node *root)
{
    Node *temp = root;
    while (temp->right)
    {
        if (temp->right)
        {
            temp = temp->right;
        }
        cout << temp->val << " ";
    }
}

int main()
{
    // Write your code here
    Node *root = input_tree();

    print_left(root);
    print_right(root);

    return 0;
}
