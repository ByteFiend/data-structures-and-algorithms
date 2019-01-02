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
  void dfs(TreeNode *root, size_t level, vector<vector<int> > &ans) {
    if (NULL == root) { return; }

    if (ans.size() <= level) { ans.push_back(vector<int>(0));}
    ans[level].push_back(root->val);

    if (root->left) { dfs(root->left, level + 1, ans); }
    if (root->right) { dfs(root->right, level + 1, ans); }
  }

  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int> > ans;
    if (NULL == root) { return ans; }

    dfs(root, 0, ans);
    return ans;
  }
};
