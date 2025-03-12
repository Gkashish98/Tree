//check wheather the Bst is valid or not

#include<iostream>
#include<bits/stdc++.h>
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
void inorderTraversal(Node* root,vector<int> &ans)
{
    if(root==NULL) return ;
    inorderTraversal(root->left,ans);
    ans.push_back(root->val);
    inorderTraversal(root->right,ans);
}
bool isValid(Node* root)
{
    vector<int>ans;
    inorderTraversal(root,ans);
    for(int i=1;i<ans.size();i++)
    {
       if(ans[i]<ans[i-1])
       {
        return false;
       }
    }
    return true;
}
int main()
{
    Node* node=createTree();
    cout<<isValid(node);
    return 0;
}
