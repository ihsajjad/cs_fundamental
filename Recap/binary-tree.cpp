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

void print_preorder(Node *root)
{
    if (!root)
        return;

    cout << root->val << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}
void print_postorder(Node *root)
{
    if (!root)
        return;

    print_postorder(root->left);
    print_postorder(root->right);
    cout << root->val << " ";
}
void print_inorder(Node *root)
{
    if (!root)
        return;

    print_inorder(root->left);
    cout << root->val << " ";
    print_inorder(root->right);
}

int main()
{

    Node *root = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node *e = new Node(60);
    Node *f = new Node(70);
    Node *g = new Node(80);
    Node *h = new Node(90);
    Node *i = new Node(100);

    root->left = a;
    root->right = b;

    a->left = c;
    a->right = d;

    b->left = e;
    b->right = f;

    c->left = g;
    c->right = h;

    d->left = i;

    print_preorder(root);
    cout << endl;
    print_inorder(root);
    cout << endl;
    print_postorder(root);

    return 0;
}