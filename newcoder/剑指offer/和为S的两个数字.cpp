class Solution {
public:
  vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    vector<int> ans;
    if (array.size() < 2) { return ans; }

    int minResult = INT_MAX;
    int left = 0, right = array.size() - 1;
    while (left < right) {
      if (array[left] + array[right] == sum) {
        if (array[left] * array[right] < minResult) {
          if (ans.empty()){
            ans.push_back(array[left]);
            ans.push_back(array[right]);
          } else {
            ans[0] = array[left];
            ans[1] = array[right];
          }
          minResult = ans[0] * ans[1];
        }
        ++left;
        --right;
      } else if (array[left] + array[right] > sum) {
        --right;
      } else {
        ++left;
      }
    }

    return ans;
  }
};
