class Solution {
public:
    bool repeatedSubstringPattern(string &s) {
        if (s.empty() || 1 == s.size()) { return false; }
        
        for (auto subSize = s.size() / 2; subSize > 0; --subSize) {
            if (s.size() % subSize != 0) { continue; }
            
            bool isRepeated = true;
            for (auto start = 0; start < subSize; ++start) {
                for (auto next = start + subSize; next < s.size(); next += subSize) {
                    if (s[start] != s[next]) {
                        isRepeated = false;
                        break;
                    }
                }
                
                if (!isRepeated) { break; }
            }
            
            if (isRepeated) { return true; }
        }
        
        return false;
    }
};