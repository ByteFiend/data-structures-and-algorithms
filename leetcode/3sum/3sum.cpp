#include <iostream>
#include <deque>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int> > ans;
    if (nums.empty()){
      return ans;
    }

    sort(nums.begin(), nums.end());
    for (unsigned i = 0; i < nums.size(); ++i){
      if (0 != i && nums[i] == nums[i - 1]){
        continue;
      }

      unsigned left = i + 1, right = nums.size() - 1;
      while (left < right){
        if (0 == nums[i] + nums[left] + nums[right]){
          ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
          do {
            ++left;
          } while (left < right && nums[left] == nums[left - 1]);
          do {
            --right;
          } while (left < right && nums[right] == nums[right + 1]);

        } else if (nums[i] + nums[left] + nums[right] > 0){
          --right;

        } else {
          ++left;
        }
      }
    }

    return ans;
  }
};
