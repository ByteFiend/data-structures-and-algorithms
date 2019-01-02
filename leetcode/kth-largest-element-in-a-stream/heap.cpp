#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class KthLargest {
public:
  KthLargest(int k, vector<int> nums) {
    max_size = k;

    while (!q.empty()){
      q.pop();
    }

    for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr){
      add(*itr);
    }
  }

  int add(int val) {
    if (q.size() < max_size){
      q.push(val);
    } else if (val > q.top()) {
      q.pop();
      q.push(val);
    }
    return q.top();
  }

private:
  int max_size;
  priority_queue<int, vector<int>, greater<int> > q;
};
