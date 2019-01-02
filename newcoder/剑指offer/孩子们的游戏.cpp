class Solution {
public:
  int LastRemaining_Solution(int n, int m){
    if (n <= 0 || m <= 0) { return -1; }
    if (1 == n) { return 0; }
    if (1 == m) { return n - 1; }

    ListNode dummy_node(0);
    ListNode *tail = &dummy_node;
    for (int i = 0; i < n; ++i){
      tail->next = new ListNode(i);
      tail = tail->next;
    }
    tail->next = dummy_node.next;
    dummy_node.next = NULL;
    tail = tail->next;

    while (tail != tail->next){
      for (int i = 1; i < m; ++i){
        tail = tail->next;
      }

      tail->val = tail->next->val;
      ListNode *tmp = tail->next;
      tail->next = tail->next->next;
      delete tmp;
    }

    int ans = tail->val;
    delete tail;
    return ans;
  }
};
