#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <assert.h>

using namespace std;

class MyQueue {
public:
  /** Initialize your data structure here. */
  MyQueue() {
    while (!in.empty()){
      in.pop();
    }
    while (!out.empty()){
      out.pop();
    }
  }

  /** Push element x to the back of queue. */
  void push(int x) {
    in.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int ret = peek();
    out.pop();
    return ret;
  }

  int peek() {
    if (out.empty()){
      while (!in.empty()){
        out.push(in.top());
        in.pop();
      }
    }
    return out.top();
  }

  bool empty() {
    return in.empty() && out.empty();
  }

private:
  stack<int> in, out;
};
