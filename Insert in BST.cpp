//insert in BST

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
    if(val==-1)
    {
        return NULL;
    }
    Node* node=new Node(val);
    cout<<"Enter left child of "<<val<<":";
    node->left=createTree();
    cout<<"Enter right child of "<<val<<":";
    node->right=createTree();
    return node;
}
Node* insertInBST(Node* root,int val)
{
    if(root==NULL) return new Node(val);
    else if(root->val>val) 
    {
         if(root->left==NULL)
         {
            root->left=new Node(val);
         }
         else insertInBST(root->left,val);
    }
    else{
        if(root->right==NULL)
        {
           root->right=new Node(val);
        }
        else insertInBST(root->right,val);
    }
    return root;
}
void inorderTraversal(Node* root)
{
    if(root==NULL) return;
    inorderTraversal(root->left);
    cout<<root->val;
    inorderTraversal(root->right);
}
int main()
{
  Node* node=createTree();
  int val;
  cin>>val;
  insertInBST(node,val);
  inorderTraversal(node);
  return 0;
}
