/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > ans;
        if (NULL == root) {
            return ans;
        }

        queue<Node *> q;
        q.push(root);
        while (false == q.empty()) {
            auto cnt = q.size();
            vector<int> level;
            for (auto i = 0; i < cnt; ++i) {
                root = q.front();
                q.pop();

                level.push_back(root->val);

                for (auto & child : root->children) {
                    if (child) { q.push(child); }
                }
            }
            ans.push_back(level);
        }

        return ans;
    }
};