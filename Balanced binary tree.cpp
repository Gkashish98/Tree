//find wheather the tee is balanced or not

class Solution {
public:  
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) 
    {
        if(root==NULL)
        {
            return true;
        }
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        if(abs(rightHeight-leftHeight)>1)
        {
            return false;
        }
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        if(!left|| !right)
        {
            return false;
        }
        return true;
    }
};
