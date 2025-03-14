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
int minimum(TreeNode* root,int mini){
    if(!root) return -1;
    if(root->val>mini){
        return root->val;
    }
    int left = minimum(root->left,mini);
    int right = minimum(root->right,mini);
    if(left==-1 || right==-1)
        return max(left,right);
        return min(left,right);
}
    int findSecondMinimumValue(TreeNode* root) {
        return minimum(root,root->val);
    }
};
