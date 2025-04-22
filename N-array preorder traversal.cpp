/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root)
    {
        vector<int>ans;
        stack<Node*>st;
        if(root!=NULL) st.push(root);
        while(st.size()>0)
        {
            Node* temp=st.top();
            st.pop();
            for(int i=temp->children.size()-1;i>=0;--i)
            {
              if(temp->children[i]!=NULL)
              {
                 st.push(temp->children[i]);
              }
            }
            ans.push_back(temp->val);
        }
        return ans;
    }
};
