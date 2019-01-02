#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <assert.h>
#include <unordered_map>

using namespace std;

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
  //这里是假设了 p，q 如果非空的话，一定是树上的节点，万一不是树上的节点呢
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (NULL == q || NULL == q){
      return NULL;
    }
    if (NULL == root || root == p || root == q || p == q){
      return root;
    }

    while (NULL != root){
      if (p->val < root->val && q->val < root->val){
        root = root->left;
      } else if (root->val < p->val && root->val < q->val){
        root = root->right;
      } else {
        return root;
      }
    }

    return NULL;
  }
};
