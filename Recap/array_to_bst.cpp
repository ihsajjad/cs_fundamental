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

Node *convert(int arr[], int n, int l, int r)
{

    if (l > r)
        return NULL;

    int mid = (l + r) / 2;

    Node *root = new Node(arr[mid]);

    Node *leftRoot = convert(arr, n, l, mid - 1);
    Node *rightRoot = convert(arr, n, mid + 1, r);

    root->left = leftRoot;
    root->right = rightRoot;

    return root;
}

void print_preorder(Node *root)
{
    if (!root)
        return;

    print_preorder(root->left);
    cout << root->val << " ";
    print_preorder(root->right);
}

int main()
{
    int n = 6;
    int arr[n] = {2, 5, 8, 12, 15, 18};

    Node *root = convert(arr, n, 0, n - 1);

    cout << root->val << " " << endl;

    print_preorder(root);

    return 0;
}