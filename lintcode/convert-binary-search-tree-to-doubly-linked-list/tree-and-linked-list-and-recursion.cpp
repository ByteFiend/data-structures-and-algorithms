/**
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
 *         this->prev = this->next = NULL;
 *     }
 * }
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
  /**
   * @param root: The root of tree
   * @return: the head of doubly list node
   */
  DoublyListNode * bstToDoublyList(TreeNode * root, DoublyListNode **tail = NULL) {
    if (NULL == root) { return NULL; }

    DoublyListNode *mid = new DoublyListNode(root->val);
    DoublyListNode *retHead = mid, *listTail = NULL;

    if (root->left){
      retHead = bstToDoublyList(root->left, &listTail);
      listTail->next = mid;
      mid->prev = listTail;
    }

    if (root->right) {
      mid->next = bstToDoublyList(root->right, &listTail);
      mid->next->prev = mid;
    } else {
      listTail = mid;
    }

    if (tail) { *tail = listTail; }

    return retHead;
  }
};
