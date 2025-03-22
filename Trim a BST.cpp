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
    void helper(TreeNode* dummy,int low,int high)
    {
        if(dummy==NULL) return ;
        while(dummy->left!=NULL)
        {
            if(dummy->left->val<low)
            {
                dummy->left=dummy->left->right;
            }
            else if(dummy->left->val>high)
            {
                dummy->left=dummy->left->left;
            }
            else
            {
                 break;
            }
        }
        while(dummy->right!=NULL)
        {
            if(dummy->right->val>high)
            {
                dummy->right=dummy->right->left;;
            }
            else if(dummy->right->val<low)
            {
                dummy->right=dummy->right->right;
            }
            else
            {
                 break;
            }
        }
        helper(dummy->left,low,high);
        helper(dummy->right,low,high);
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) 
    {
        TreeNode* dummy=new TreeNode(INT_MAX);
        dummy->left=root;
        helper(dummy,low,high);
        return dummy->left;
        
    }
};
