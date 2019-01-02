class Solution {
 public:
 vector<vector<int> > FindContinuousSequence(int sum) {
   vector<vector<int> > ans;
   if (sum < 3) { return ans; }

   int half = ((sum + 1) >> 1);
   int left = 1, right = 2, curSum = 3;
   while (left < right && right <= half) {
     while (curSum < sum && right <= half) {
       ++right;
       curSum += right;
     }
     while (curSum > sum && left < right) {
       curSum -= left;
       ++left;
     }

     if (curSum == sum) {
       vector<int> sequence;
       for (int i = left; i <= right; ++i){
         sequence.push_back(i);
       }
       ans.push_back(sequence);

       curSum -= left;
       ++left;
       ++right;
       curSum += right;
     }
   }

   return ans;
 }
};
