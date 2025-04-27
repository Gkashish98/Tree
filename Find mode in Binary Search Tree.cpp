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
    void inorderTraversal(TreeNode* root,vector<int> &ans)
    {
        if(root==NULL)
        {
            return;
        }
        inorderTraversal(root->left,ans);
        ans.push_back(root->val);
        inorderTraversal(root->right,ans);
    }
    vector<int> findMode(TreeNode* root)
    {
        vector<int>ans;
        inorderTraversal(root,ans);
        unordered_map<int,int>mp;
        for(int i=0;i<ans.size();i++)
        {
            mp[ans[i]]++;
        }
        int maxVal=INT_MIN;
        for(auto &ele:mp)
        {
           maxVal=max(maxVal,ele.second);
        }
        vector<int>result;
        for(auto &ele:mp)
        {
            if(ele.second==maxVal)
            {
              result.push_back(ele.first);
            }
        }
        return result;
    }
};
