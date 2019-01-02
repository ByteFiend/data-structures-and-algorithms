#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <assert.h>
#include <unordered_map>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (NULL == head){
      return NULL;
    }

    ListNode dummyNode(0);
    dummyNode.next = head;

    ListNode *one_step = head, *two_step = head->next;
    while (NULL != two_step && one_step != two_step){
      if (head == two_step || head == two_step->next){
        return head;
      }
      if (NULL == two_step->next){
        return NULL;
      }

      two_step = two_step->next->next;
      one_step = one_step->next;
    }
    if (NULL == two_step){
      return NULL;
    }

    one_step = &dummyNode;
    while (one_step != two_step){
      one_step = one_step->next;
      two_step = two_step->next;
    }

    return one_step;
  }
};
