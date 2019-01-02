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
    int maxDepth(Node *root, int depth) {
        if (NULL == root) { return depth; }

        int ans = depth + 1;
        for (auto & child : root->children) {
            ans = max(ans, maxDepth(child, depth + 1));
        }
        return ans;
    }

    int maxDepth(Node* root) {
        int ans = 0;
        if (NULL == root) { return ans; }

        return maxDepth(root, ans);
    }
};