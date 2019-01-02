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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
    if (NULL == root) { return ans; }

    path.push_back(root->val);
    if (NULL == root->left && NULL == root->right) {
      if (sum == root->val && !path.empty()) { ans.push_back(path); }
    } else {
      pathSum(root->left, sum - root->val);
      pathSum(root->right, sum - root->val);
    }
    path.pop_back();

    return ans;
	}

  vector<vector<int> > ans;
  vector<int> path;
};
