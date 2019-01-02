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

class MinStack {
public:
  MinStack() {
    while (!s_nums.empty()){
      s_nums.pop();
    }
    while (!s_min.empty()){
      s_min.pop();
    }
  }

  void push(int x) {
    s_nums.push(x);
    if (!s_min.empty() && s_min.top() < x){
      s_min.push(s_min.top());
    } else {
      s_min.push(x);
    }
  }

  void pop() {
    s_nums.pop();
    s_min.pop();
  }

  int top() {
    return s_nums.top();
  }

  int getMin() {
    return s_min.top();
  }
private:
  stack<int> s_nums, s_min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
