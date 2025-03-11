//inorder traversal in binary tree

#include<bits/stdc++.h>
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
vector<int> inOrderTraversal(Node* node)
{
   vector<int>ans;
   stack<Node*>st;
   Node* node1=node;
   while(st.size()>0 || node1!=NULL)
   {
        if(node1!=NULL)
        { 
            st.push(node1);
            node1=node1->left;
        }
        else
        {
            Node* temp=st.top();
            st.pop();
            ans.push_back(temp->val);
            node1=temp->right;
        }
    }
   return ans;
}
/*
recursive approach
void inOrderTraversal(Node* node)
{
    if(node==NULL)
    {
       return;
    }
    preOrderTraversal(node->left);
    cout<<"node->val";
    preOrderTraversal(node->right);
}
*/
int main()
{
    Node* node=createTree();
    vector<int>result=inOrderTraversal(node);
    for(auto &val:result)
    {
        cout<<val<<" ";
    }
    return 0;
}
