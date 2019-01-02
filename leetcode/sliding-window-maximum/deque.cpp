#include <iostream>
#include <deque>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    if (k <= 0 || 0 == nums.size()){
      return ans;
    }

    deque<int> q;
    for (int idx = 0; idx < nums.size(); ++idx){
      if (idx >= k && q.front() <= idx - k){
        q.pop_front();
      }
      while (!q.empty() && nums[q.back()] <= nums[idx]){
        q.pop_back();
      }
      q.push_back(idx);
      if (idx >= k - 1){
        ans.push_back(nums[q.front()]);
      }
    }

    return ans;
  }
};

void printVector(vector<int> &to_print){
  for (vector<int>::iterator itr = to_print.begin(); itr != to_print.end(); ++itr){
    cout << *itr << endl;
  }
  cout << endl;
}

void judge(vector<int> &my, vector<int> &expected){
  assert(my.size() == expected.size());
  for (int i = 0; i < my.size(); ++i){
    assert(my[i] == expected[i]);
  }
}

struct Case {
  int k;
  vector<int> nums;
  vector<int> expected;
};

int main(){
  vector<int> nums, ans, expected;
  int k;
  Solution s;

  vector<Case> cases;

  k = 3;
  nums = {1, 3, -1, -3, 5, 3, 6, 7};
  expected = {3, 3, 5, 5, 6, 7};
  cases.push_back(Case{k, nums, expected});

  k = 3;
  nums = {1, 3, 1, 2, 0, 5};
  expected = {3, 3, 2, 5};
  cases.push_back(Case{k, nums, expected});

  k = 2;
  nums = {7, 2, 4};
  expected = {7, 4};
  cases.push_back(Case{k, nums, expected});

  k = 10;
  nums = {-95, 92, -85, 59, -59, -14, 88, -39, 2, 92, 94, 79, 78, -58, 37, 48, 63, -91, 91, 74, -28, 39, 90, -9, -72, -88, -72, 93, 38, 14, -83, -2, 21, 4, -75, -65, 3, 63, 100, 59, -48, 43, 35, -49, 48, -36, -64, -13, -7, -29, 87, 34, 56, -39, -5, -27, -28, 10, -57, 100, -43, -98, 19, -59, 78, -28, -91, 67, 41, -64, 76, 5, -58, -89, 83, 26, -7, -82, -32, -76, 86, 52, -6, 84, 20, 51, -86, 26, 46, 35, -23, 30, -51, 54, 19, 30, 27, 80, 45, 22};
  expected = {92, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 91, 91, 91, 91, 91, 91, 91, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 63, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 59, 48, 87, 87, 87, 87, 87, 87, 87, 87, 87, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 78, 78, 78, 78, 78, 83, 83, 83, 83, 83, 83, 86, 86, 86, 86, 86, 86, 86, 86, 86, 86, 84, 84, 84, 54, 54, 54, 54, 80, 80, 80};
  cases.push_back(Case{k, nums, expected});

  for (int i = 0; i < cases.size(); ++i){
    ans = s.maxSlidingWindow(cases[i].nums, cases[i].k);
    judge(ans, cases[i].expected);
    cout << "passs case " << i << endl;
  }
}
