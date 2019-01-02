/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (NULL == head){
      return NULL;
    }

    for (RandomListNode *cur = head; NULL != cur; cur = cur->next->next){
      RandomListNode *tmp = new RandomListNode(cur->label);
      tmp->next = cur->next;
      cur->next = tmp;
    }

    for (RandomListNode *cur = head; NULL != cur; cur = cur->next->next){
      if (cur->random){
        cur->next->random = cur->random->next;
      }
    }

    RandomListNode *newHead = head->next;
    RandomListNode *oldTail = head, *newTail = newHead;
    for (RandomListNode *cur = newHead->next; NULL != cur; cur = cur->next->next){
      oldTail->next = cur;
      oldTail = oldTail->next;

      newTail->next = cur->next;
      newTail = newTail->next;
    }
    oldTail->next = NULL;

    return newHead;
  }
};
