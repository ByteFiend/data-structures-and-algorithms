class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (NULL == headA || NULL == headB){
      return NULL;
    }
    if (headA == headB){
      return headA;
    }

    ListNode *tailA = headA, *tailB = headB;
    int lenA = 0, lenB = 0;
    for (tailA = headA; NULL != tailA; tailA = tailA->next){
      ++lenA;
    }
    for (tailB = headB; NULL != tailB; tailB = tailB->next){
      ++lenB;
    }

    if (tailA != tailB){
      return NULL;
    }

    if (lenA > lenB){
      for (int i = 0; i < lenA - lenB; ++i){
        headA = headA->next;
      }
    } else if (lenB > lenA){
      for (int i = 0; i < lenB - lenA; ++i){
        headB = headB->next;
      }
    }

    for (; headA != headB;){
      if (headA == headB){
        return headA;
      }

      headA = headA->next;
      headB = headB->next;
    }

    return headA;
  }
};
