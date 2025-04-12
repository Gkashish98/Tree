#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return nullptr;

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if (root->val == 0 && !root->left && !root->right) {
            return nullptr;
        }

        return root;
    }
};
