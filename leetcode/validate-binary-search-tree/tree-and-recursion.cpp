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
  bool helper(TreeNode *root, int min, bool check_min, int max, bool check_max){
    if (NULL == root){
      return true;
    }

    if (check_min && root->val <= min){
      return false;
    }
    if (check_max && root->val >= max){
      return false;
    }

    return helper(root->left, min, check_min, root->val, true) && helper(root->right, root->val, true, max, check_max);
  }

  bool isValidBST(TreeNode* root) {
    if (NULL == root){
      return true;
    }

    return helper(root, 0, false, 0, false);
  }
};
