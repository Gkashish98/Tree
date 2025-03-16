//find the sum of all the left leaves

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
    void preOrder(TreeNode* root,vector<int>& ans)
    {
        if(root==NULL) return;
        if(root->left && root->left->left==NULL && root->left->right==NULL)
        {
            ans.push_back(root->left->val);
        }
        preOrder(root->right,ans);
        preOrder(root->left,ans);
    }
    int sumOfLeftLeaves(TreeNode* root) 
    {
        vector<int>ans;
        preOrder(root,ans);
        int sum=0;
        for(int i=0;i<ans.size();i++)
        {
            sum=sum+ans[i];
        }
        return sum;
    }
};
