/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if (NULL == root) { return ans; }

        deque<TreeNode *> q;
        q.push_back(root);
        bool needReverse = false;
        while (false == q.empty()) {
            auto cnt = q.size();

            vector<int> level;
            for (auto i = 0; i < cnt; ++i) {
                if (needReverse) {
                    root = q.back();
                    q.pop_back();

                    if (root->right) { q.push_front(root->right); }
                    if (root->left) { q.push_front(root->left); }
                } else {
                    root = q.front();
                    q.pop_front();

                    if (root->left) { q.push_back(root->left); }
                    if (root->right) { q.push_back(root->right); }
                }
                level.push_back(root->val);
            }

            needReverse = !needReverse;

            ans.push_back(level);
        }

        return ans;
    }
};