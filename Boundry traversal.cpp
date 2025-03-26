/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    void leftBoundry(Node* node, vector<int>& ans) {
        if (node == NULL || (node->left == NULL && node->right == NULL)) 
            return;  // Skip null and leaf nodes

        ans.push_back(node->data);
        if (node->left) 
            leftBoundry(node->left, ans);
        else 
            leftBoundry(node->right, ans);
    }

    void leafNode(Node* node, vector<int>& ans) {
        if (node == NULL) return;

        if (node->left == NULL && node->right == NULL) {
            ans.push_back(node->data);
            return;
        }
        leafNode(node->left, ans);
        leafNode(node->right, ans);
    }

    void rightBoundry(Node* node, vector<int>& ans) {
        if (node == NULL || (node->left == NULL && node->right == NULL)) 
            return;  // Skip null and leaf nodes

        // Traverse first to ensure correct order
        if (node->right) 
            rightBoundry(node->right, ans);
        else 
            rightBoundry(node->left, ans);

        ans.push_back(node->data);  // Push after recursion for correct order
    }

    vector<int> boundaryTraversal(Node* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        if(root->left==NULL && root->right==NULL)
        {
             ans.push_back(root->data);
             return ans;
        }
        ans.push_back(root->data);  // Add root node

        leftBoundry(root->left, ans);  // Process left boundary
        leafNode(root, ans);           // Collect leaf nodes
        rightBoundry(root->right, ans); // Process right boundary

        return ans;
    }
};
