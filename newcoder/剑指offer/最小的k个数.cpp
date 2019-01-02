#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int partition(vector<int> &nums, int left, int right){
    if (0 == nums.size() || left > right ) { return -1; }
    if (left == right) { return left; }

    srand((unsigned)time(NULL));

    int pivotIdx = left + rand() % (right - left + 1);
    cout << pivotIdx << endl;

    int pivot = nums[pivotIdx];
    nums[pivotIdx] = nums[right];
    nums[right] = pivot;

    int tmp;
    pivotIdx = left;
    for (int idx = left; idx < right; ++idx) {
      if (nums[idx] < pivot) {
        tmp = nums[idx];
        nums[idx] = nums[pivotIdx];
        nums[pivotIdx] = tmp;
        ++pivotIdx;
      }
    }

    nums[right] = nums[pivotIdx];
    nums[pivotIdx] = pivot;
    return pivotIdx;
  }

  vector<int> GetLeastNumbers_Solution(vector<int> &input, int k) {
    vector<int> ans;
    if (k <= 0 || 0 == input.size() || k > input.size()) { return ans; }
    if (k == input.size()) { return input; }

    int left = 0, right = input.size() - 1;
    while (true) {
      int pivotIdx = partition(input, left, right);
      if (k - 1 == pivotIdx) {
        break;
      } else if (pivotIdx < k - 1) {
        left = pivotIdx + 1;
      } else {
        right = pivotIdx - 1;
      }
    }

    ans.assign(input.begin(), input.begin() + k);
    return ans;
  }
};

int main(){
  Solution s;
  vector<int> input;

  input.clear();
  input.push_back(4);
  input.push_back(5);
  input.push_back(1);
  input.push_back(6);
  input.push_back(2);
  input.push_back(7);
  input.push_back(3);
  input.push_back(8);

  vector<int> ans = s.GetLeastNumbers_Solution(input, 4);
  for (vector<int>::iterator itr = ans.begin(); itr != ans.end(); ++itr){
    cout << *itr << " ";
  }
  cout << endl;
}
