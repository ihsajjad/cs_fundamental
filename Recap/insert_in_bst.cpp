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

void input_bst(Node *&root, int val)
{
    if (!root)
    {
        root = new Node(val);
        return;
    }

    if (root->val < val)
    {
        if (!root->right)
            root->right = new Node(val);
        else
            input_bst(root->right, val);
    }
    else
    {
        if (!root->left)
            root->left = new Node(val);
        else
            input_bst(root->left, val);
    }
}

int main()
{

    return 0;
}