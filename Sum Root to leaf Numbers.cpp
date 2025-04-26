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
    void findNumbers(TreeNode* root,vector<string> &ans,string s)
    {
       if(root==NULL)
       {
         return;
       }
       s+=to_string(root->val);
       if(root->left==NULL && root->right==NULL)
       {
          ans.push_back(s);
          return;
       }
       findNumbers(root->left,ans,s);
       findNumbers(root->right,ans,s);
    }
    int sumNumbers(TreeNode* root)
    {
        vector<string>ans;
        string s;
        findNumbers(root,ans,s);
        int sum=0;
        for(auto &ele:ans)
        {
            sum+=stoi(ele);
        }
        return sum;
    }
};
