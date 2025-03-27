/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) 
    {
        vector<int>ans;
        if(root==NULL) return ans;
        map<int,int>mp;
        queue<pair<Node* ,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int line=it.second;
            if(mp.find(line)==mp.end()) mp[line]=node->data;
            if(node->left!=NULL)
            {
                q.push({node->left,line-1});
            }
            if(node->right!=NULL)
            {
                q.push({node->right,line+1});
            }
        }
        for(auto val:mp)
        {
            ans.push_back(val.second);
        }
        return ans;
    }
};
