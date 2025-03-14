// find the minimum depth of the binary tree

#include<iostream>
using namespace std;
class Node
{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val)
    {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* createTree()
{
    int val;
    cin>>val;
    if(val==-1) return NULL;
    Node* node= new Node(val);
    cout<<"Enter left child of "<<val<<":";
    node->left=createTree();
    cout<<"Enter right child of "<<val<<":";
    node->right=createTree();
    return node;
}
int minDepth(Node* root) {
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL)
    {
        return 1+minDepth(root->right);
    }
    if(root->right==NULL)
    {
        return 1+minDepth(root->left);
    }
    return 1+min(minDepth(root->left),minDepth(root->right));
}
int main()
{
    Node* node=createTree();
    int result=minDepth(node);
    cout<<result<<endl;
    return 0;
}
