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
    vector<int> postorder(Node* root)
    {
        vector<int>ans;
        stack<Node*>st;
        if(root!=NULL)
        {
            st.push(root);
        }
        while(!st.empty())
        {
            Node* node=st.top();
            st.pop();
            ans.push_back(node->val);
            for(Node*child:node->children)
            {
                if(child!=NULL)
                {
                    st.push(child);
                }
            }

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
