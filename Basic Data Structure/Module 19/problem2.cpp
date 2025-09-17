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

Node* input_tree()
{   
    int val;cin >> val;
    Node *root;
    if(val == -1) root = NULL;
    else root = new Node(val);
    
    queue<Node*> q;
    if(root) q.push(root);
    
    while(!q.empty())
    {
        Node * p = q.front();
        q.pop();
        
        int l, r; cin >> l >> r;
        Node *myLeft, *myRight;
        if(l==-1) myLeft = NULL;
        else myLeft = new Node(l);
        if(r==-1) myRight = NULL;
        else myRight = new Node(r);
        
        p->left = myLeft;
        p->right = myRight;
        
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    
    return root;
}

vector<int> leafs;

void get_leafs(Node * root)
{
    if(!root) return;
    
    if(!root->left && !root->right)
    {
        leafs.push_back(root->val);
    }
    
    if(root->left) get_leafs(root->left);
    if(root->right) get_leafs(root->right);
}

int main()
{
    // Write your code here
    Node *root = input_tree();
    
    get_leafs(root);
    
    reverse(leafs.begin(), leafs.end());
    
    for(int x: leafs) cout << x << " ";
    
    
    return 0;
}
