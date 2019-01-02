class Solution {
 public:
 vector<vector<int> > FindContinuousSequence(int sum) {
   vector<vector<int> > ans;
   if (sum < 3) { return ans; }

   int maxNumsCnt = ((sum + 1) >> 1);
   int left, right;
   for (int numsCnt = maxNumsCnt; numsCnt >= 2; --numsCnt) {
     int mid = sum / numsCnt;
     if (0 == (numsCnt & 1)) {
       if (mid < (numsCnt >> 1)) { continue; }
       if ((mid + mid + 1) * (numsCnt >> 1) != sum) { continue; }

       left = mid - (numsCnt >> 1) + 1;
       right = mid + (numsCnt >> 1);
     } else {
       if (0 != sum % numsCnt) { continue; }
       if (mid <= (numsCnt >> 1)) { continue; }

       left = mid - (numsCnt >> 1);
       right = mid + (numsCnt >> 1);
     }

     vector<int> sequence;
     for (int i = left; i <= right; ++i){
       sequence.push_back(i);
     }
     ans.push_back(sequence);
   }

   return ans;
 }
};
