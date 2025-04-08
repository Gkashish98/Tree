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
    TreeNode* treeBuilder(vector<int> &preorder,int prestart,int preend,vector<int> &inorder,int instart,int inend,unordered_map<int,int> &mp)
    {
        if(prestart>preend || instart>inend)
        {
            return NULL;
        }
        TreeNode* rootNode=new TreeNode(preorder[prestart]);
        int rootNodeIndex=mp[rootNode->val];
        int leftSubTreeSize= rootNodeIndex-instart;
        rootNode->left=treeBuilder(preorder,prestart+1,prestart+leftSubTreeSize,inorder,instart,rootNodeIndex-1,mp);
        rootNode->right=treeBuilder(preorder,prestart+leftSubTreeSize+1,preend,inorder,rootNodeIndex+1,inend,mp);
        return rootNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return treeBuilder(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        
    }
};
