#include <iostream>
#include <deque>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
  void helper(unordered_map<int, unordered_set<int> > &s, int target, vector<int> &ans){
    if (s.empty()){
      return;
    }

    unordered_map<int, unordered_set<int> >::iterator itr, found;
    for (itr = s.begin(); itr != s.end(); ++itr){
      int idx = *(itr->second.begin());
      itr->second.erase(idx);

      found = s.find(target - itr->first);
      if (s.end() != found && false == (found->second).empty()){
        ans.push_back(idx);
        ans.push_back(*(found->second.begin()));
        return;
      }
    }

    return;
  }

  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    if (nums.empty()){
      return ans;
    }

    unordered_map<int, unordered_set<int> > s;
    for (unsigned i = 0; i < nums.size(); ++i){
      if (s.end() == s.find(nums[i])){
        s[nums[i]] = unordered_set<int>{};
      }
      s[nums[i]].insert(i);
    }

    helper(s, target, ans);
    return ans;
  }
};
