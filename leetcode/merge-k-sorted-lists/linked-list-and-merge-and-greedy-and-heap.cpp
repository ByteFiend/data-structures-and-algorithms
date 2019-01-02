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

struct List {
  ListNode *head;
  int len;
  List(ListNode *_head, int _len): head(_head), len(_len) {}

  friend bool operator < (const List &a,const List &b) {
    return (a.len < b.len);
  }
};

class Solution {
public:
  ListNode * merge(ListNode *l1, ListNode *l2){
    if (NULL == l1){
      return l2;
    } else if (NULL == l2){
      return l1;
    }

    ListNode dummy_node(0);
    ListNode *tail = &dummy_node;
    while (NULL != l1 && NULL != l2){
      if (l1->val < l2->val){
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }
    if (NULL != l1){
      tail->next = l1;
    } else if (NULL != l2){
      tail->next = l2;
    }

    return dummy_node.next;
  }

  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()){
      return NULL;
    }

    priority_queue<List> q;
    for (vector<ListNode*>::iterator itr = lists.begin(); itr != lists.end(); ++itr){
      int len = 0;
      for (ListNode *cur = *itr; NULL != cur; cur = cur->next){
        ++len;
      }

      q.push(List(*itr, len));
    }

    while (q.size() > 1){
      List l1 = q.top();
      q.pop();
      List l2 = q.top();
      q.pop();

      ListNode *new_list = merge(l1.head, l2.head);
      q.push(List(new_list, l1.len + l2.len));
    }

    return q.top().head;
  }
};

int main(){
  Solution s;
  vector<ListNode *> to_merge;

  ListNode a(1), b(4), c(5);
  a.next = &b;
  b.next = &c;
  to_merge.push_back(&a);

  ListNode d(1), e(3), f(4);
  d.next = &e;
  e.next = &f;
  to_merge.push_back(&d);

  ListNode g(2), h(6);
  g.next = &h;
  to_merge.push_back(&g);

  s.mergeKLists(to_merge);
}
