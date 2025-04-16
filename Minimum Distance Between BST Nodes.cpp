/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findVal(TreeNode* root,vector<int> &v)
    {
        if(root==NULL)
        {
            return;
        }
        findVal(root->left,v);
        v.push_back(root->val);
        findVal(root->right,v);
    }
    int minDiffInBST(TreeNode* root) 
    {
        if(root==NULL || root->left==NULL && root->right==NULL)
        {
            return 0;
        }
        vector<int>v;
        int minDiff=INT_MAX;
        findVal(root,v);
        for(int i=1;i<v.size();i++)
        {
            minDiff=min(minDiff,abs(v[i]-v[i-1]));
        }
        return minDiff;
    }
};
