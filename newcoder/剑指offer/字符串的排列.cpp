class Solution {
public:
    void swap(string &str, int idx1, int idx2){
        char tmp = str[idx1];
        str[idx1] = str[idx2];
        str[idx2] = tmp;
    }
    
    void helper(string &str, int begin, int end, vector<string> &ans){
        if (begin >= end){
            ans.push_back(str);
            return;
        }
        
        for (int i = begin; i < end; ++i){
            if (i != begin && str[i] == str[begin]){
                continue;
            }
            
            swap(str, begin, i);
            helper(str, begin + 1, end, ans);
            swap(str, begin, i);
        }
    }
    
    vector<string> Permutation(string &str) {
        vector<string> ans;
        if (str.empty()){
            return ans;
        }
        
        helper(str, 0, str.size(), ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
