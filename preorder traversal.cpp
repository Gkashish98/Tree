//preorder traversal in tree.

#include<iostream>
#include<stack>
#include<vector>
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
        this->right=NULL;
        this->left=NULL;
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
    Node* node = new Node(val);
    cout<<"Enter left child of "<<val<<":";
    node->left=createTree();
    cout<<"Enter right child of "<<val<<":";
    node->right=createTree();
    return node;
}
vector<int> preOrderTraversal(Node* node)
{
   vector<int>ans;
   stack<Node*>st;
   if(node!=NULL)
   { 
     st.push(node);
   }
   while(st.size()>0)
   {
     Node* temp=st.top();
     st.pop();
     ans.push_back(temp->val);
     if(temp->right!=NULL) st.push(temp->right);
     if(temp->left!=NULL) st.push(temp->left);
   }
   return ans;
}
/*
recursive approach
void preOrderTraversal(Node* node)
{
    if(node==NULL)
    {
       return;
    }
    cout<<"node->val";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}
*/
int main()
{
    Node* node=createTree();
    vector<int>result=preOrderTraversal(node);
    for(auto &val:result)
    {
        cout<<val<<" ";
    }
    return 0;
}
