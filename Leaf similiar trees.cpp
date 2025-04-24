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
    void inorderTraversal(TreeNode* root,vector<int> &v)
    {
        if(root==NULL)
        {
            return;
        }
        inorderTraversal(root->left,v);
        inorderTraversal(root->right,v);
        if(root->left==NULL && root->right==NULL) v.push_back(root->val);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int>v1;
        vector<int>v2;
        inorderTraversal(root1,v1);
        inorderTraversal(root2,v2);
        int i=0;
        int j=0;
        while(i<v1.size() && j<v2.size())
        {
            if(v1[i]!=v2[j])
            {
                return false;
            }
            i++;
            j++;
        }
        if(v1.size()!=v2.size())
        {
            return false;
        }
        return true;
    }
};
