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
  vector<int> inorderTraversal(TreeNode* root) {
    ans.clear();
    if (NULL == root){
      return ans;
    }

    stack<TreeNode*> s;
    TreeNode *cur = root;
    while (!s.empty() || cur){
      while (cur){
        s.push(cur);
        cur = cur->left;
      }

      if (!s.empty()){
        cur = s.top();
        s.pop();

        ans.push_back(cur->val);

        cur = cur->right;
      }
    }

    return ans;
  }

  vector<int> ans;
};
