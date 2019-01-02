/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (NULL == root) { return ans; }

        stack<Node *> s;
        s.push(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();

            ans.push_back(root->val);

            for (auto itr = (root->children).rbegin(); itr != (root->children).rend(); ++itr) {
                if (*itr) {
                    s.push(*itr);
                }
            }
        }

        return ans;
    }
};