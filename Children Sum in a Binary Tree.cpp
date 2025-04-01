struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
      if(root==NULL || (root->left==NULL && root->right==NULL)) return 1;
      int leftData=(root->left!=NULL)?root->left->data:0;
      int rightData=(root->right!=NULL)?root->right->data:0;
      if(root->data==(leftData+rightData))
      {
          return isSumProperty(root->left) && isSumProperty(root->right);
      }
      return 0;
    }
};
