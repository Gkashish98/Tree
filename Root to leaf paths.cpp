/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void helper(Node* root,vector<vector<int>> &ans,vector<int> &val)
    {
        if(root==NULL) return;
        val.push_back(root->data);
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(val);
        }
        else
        {
            helper(root->left,ans,val);
            helper(root->right,ans,val);
        }
        val.pop_back();
    }
    vector<vector<int>> Paths(Node* root)
    {
        vector<vector<int>>ans;
        vector<int>val;
        helper(root,ans,val);
        return ans;
    }
};
