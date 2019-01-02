#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <assert.h>

using namespace std;

class MyStack {
public:
  MyStack() {
    while (!q1.empty()){
      q1.pop();
    }
    while (!q2.empty()){
      q2.pop();
    }

    primary = &q1;
    helper = &q2;
  }

  void push(int x) {
    primary->push(x);
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int ret = top();
    primary->pop();
    return ret;
  }

  int top() {
    if (primary->empty()){
      swap(primary, helper);
    }
    while (primary->size() > 1){
      helper->push(primary->front());
      primary->pop();
    }
    return primary->front();
  }

  bool empty() {
    return primary->empty() && helper->empty();
  }

private:
  queue<int> q1, q2;
  queue<int> *primary, *helper;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
