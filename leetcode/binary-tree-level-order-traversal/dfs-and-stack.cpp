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

    stack<pair<int, TreeNode *> > s;
    s.push(make_pair(0, root));

    while (!s.empty()){
      int level = s.top().first;
      TreeNode *p_node = s.top().second;
      s.pop();

      if (ans.size() <= level) { ans.push_back(vector<int>(0)); }
      ans[level].push_back(p_node->val);

      if (p_node->right) { s.push(make_pair(level + 1, p_node->right)); }
      if (p_node->left) { s.push(make_pair(level + 1, p_node->left)); }
    }
  }

  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int> > ans;
    if (NULL == root) { return ans; }

    dfs(root, 0, ans);
    return ans;
  }
};
