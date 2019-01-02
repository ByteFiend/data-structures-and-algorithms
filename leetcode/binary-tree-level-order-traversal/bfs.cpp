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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int> > ans;
    if (NULL == root) { return ans; }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()){
      vector<int> curLevel;
      int levelSize = q.size();

      for (int i = 0; i < levelSize; ++i){
          TreeNode *p_node = q.front();
          q.pop();
          curLevel.push_back(p_node->val);

          if (p_node->left){ q.push(p_node->left); }
          if (p_node->right) { q.push(p_node->right); }
      }

      ans.push_back(curLevel);
    }

    return ans;
  }
};
