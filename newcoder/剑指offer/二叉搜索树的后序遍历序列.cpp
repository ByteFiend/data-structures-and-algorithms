class Solution {
public:
    bool helper(vector<int> &sequence, int left, int right){
        if (sequence.empty() || left < 0 || right < 0 || left > right) { return false; }
        if (left == right) { return true; }
        
        int idx = left;
        while (idx < right) {
            if (sequence[idx] > sequence[right]) { break; }
            ++idx;
        }
        
        int rightBegin = idx;
        while (idx < right) {
            if (sequence[idx] < sequence[right]) { return false; }
            ++idx;
        }
        
        if (left < rightBegin) {
            if (false == helper(sequence, left, rightBegin - 1)) { return false; }
        }
        
        if (rightBegin < right) {
            return helper(sequence, rightBegin, right - 1);
        }
        
        return true;
    }
    
    bool VerifySquenceOfBST(vector<int> &sequence) {
        return helper(sequence, 0, sequence.size() - 1);
    }
};
