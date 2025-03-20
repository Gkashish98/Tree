//find the maximum path sum in a binary tree

// User Fuction template for C++
/*
// Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
     int maxSum;
     int helper(Node* root)
     {
         if(root==NULL) return 0;
         int l=helper(root->left);
         int r=helper(root->right);
         
         int a=l+r+root->data;
         int b=max(l,r)+root->data;
         int c=root->data;
         
         maxSum=max({maxSum,a,b,c});
         
         return max(b,c);
     }
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) 
    {
      maxSum=INT_MIN;
      helper(root);
      return maxSum;
    }
};
