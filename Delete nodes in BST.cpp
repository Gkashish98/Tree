#include<iostream>
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
        this->left=NULL;
        this->right=NULL;
        this->val=val;
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
    cout<<"Enter left child "<<val<<":";
    node->left=createTree();
    cout<<"Enter right child "<<val<<":";
    node->right=createTree();
    return node;
}

Node* inorderPrededcessor(Node* root)
{
    Node* pred=root->left;
    while(pred->right!=NULL)
    {
        pred=pred->right;
    }
    return pred;
}

Node* deleteNodeFromBST(Node* root,int key)
{
    if(root==NULL) return NULL;
    if(root->val==key)
    {
        if(root->left==NULL && root->right==NULL)
        {
            return NULL;
        }
        else if(root->left==NULL || root->right==NULL)
        {
           if(root->left!=NULL)
           {
             return root->left;
           }
           else
           {
              return root->right;
           }
        }
        else if(root->left!=NULL && root->right!=NULL)
        {
           Node* pred=inorderPrededcessor(root);
           root->val=pred->val;
           root->left=deleteNodeFromBST(root->left,pred->val);
        }
    }
    else if(root->val>key)
    {
        root->left=deleteNodeFromBST(root->left,key);
    }
    else
    {
        root->right=deleteNodeFromBST(root->right,key);
    }
    return root;
}

void preTraversal(Node* root,vector<int> &ans)
{
    if(root==NULL) return;
    ans.push_back(root->val);
    preTraversal(root->left,ans);
    preTraversal(root->right,ans);
}
int main()
{
    Node* root=createTree();
    int val;
    cout<<"Enter the key to be deleted "<<":";
    cin>>val;
    vector<int>ans;
    root=deleteNodeFromBST(root,val);
    preTraversal(root,ans);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
