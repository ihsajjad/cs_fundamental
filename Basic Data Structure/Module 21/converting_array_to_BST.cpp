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

Node *input_node()
{
    int val;
    cin >> val;
    queue<Node *> q;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);

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

void level_order(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        cout << p->val << " ";

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
}

void insert(Node *&root, int val)
{
    Node *newnode = new Node(val);
    if (!root)
        root = newnode;

    if (root->val > val)
    {
        if (!root->left)
            root->left = newnode;
        else
            insert(root->left, val);
    }
    else
    {
        if (!root->right)
            root->right = newnode;
        else
            insert(root->right, val);
    }
}

Node *convert(int a[], int l, int r)
{
    if (l > r)
        return NULL;

    int mid = (l + r) / 2;

    Node *root = new Node(a[mid]);
    Node *leftRoot = convert(a, l, mid - 1);
    Node *rightRoot = convert(a, mid + 1, r);

    root->left = leftRoot;
    root->right = rightRoot;

    return root;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Node *root = convert(a, 0, n - 1);
    level_order(root);

    return 0;
}