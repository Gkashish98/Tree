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
    cout<<"Enter left child of "<<val<<": ";
    node->left=createTree();
    cout<<"Enter right child of "<<val<<": ";
    node->right=createTree();
    return node;
}

Node* find(Node* root, int key)
{
    if (root == NULL || root->val == key)
        return root;
    if (key < root->val)
        return find(root->left, key);
    else
        return find(root->right, key);
}


Node* lca(Node* root, Node* p,Node* q)
{
    if(root->val > p->val && root->val > q->val)
    {
        return lca(root->left,p,q);
    }
    else if(root->val < p->val && root->val < q->val)
    {
        return lca(root->right,p,q);
    }
    return root;
}

int distBetween(Node* root, int k,int dist)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->val == k)
    {
       return dist;
    }
    int left=distBetween(root->left,k,dist+1);
    if(left!=-1)
    {
        return left;
    }
    return distBetween(root->right,k,dist+1);
}

int Dist(Node* root,int p,int q)
{
    Node* pNode = find(root, p);
    Node* qNode = find(root, q);
    Node* lowestCA=lca(root,pNode,qNode);
    int d1=distBetween(lowestCA,p,0);
    int d2=distBetween(lowestCA,q,0);
    return d1+d2;
}
int main()
{
    Node* root=createTree();
    int p,q;
    cout<<"Enter p";
    cin>>p;
    cout<<"Enter q";
    cin>>q;
    int ans=Dist(root,p,q);
    cout<<ans<<endl;
    return 0;
}
