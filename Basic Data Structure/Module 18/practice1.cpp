#include <bits/stdc++.h> 
#include <iostream>

    // Following is the BinaryTreeNode class structure

    template <typename T>

    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

BinaryTreeNode<int>* input_tree()
{
    int val; 
    cin >> val;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(val);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty())
    {
        BinaryTreeNode<int> * f = q.front();
        q.pop();

        int l, r; cin >> l >> r;

        BinaryTreeNode<int> * myLeft, *myRight;
        if(l == -1) myLeft = NULL;
        else myLeft = new BinaryTreeNode<int>(l);
        if(r == -1) myRight = NULL;
        else myRight = new BinaryTreeNode<int>(r);

        f->left = myLeft;
        f->right = myRight;

        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
        
    }

    return root;
}

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    int n; 
    cin >> n;

    for(int i = 0; i < 3; i++)
    {
        BinaryTreeNode<int>* newTree = input_tree();

        queue<BinaryTreeNode<int> *> q;
        q.push(root);
        while(!q.empty())
        {
        BinaryTreeNode<int> * temp = q.front();
        q.pop();

        cout << temp->val << " ";

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);

        }
    cout << endl;

    }
    
    //  Write your code here.

}