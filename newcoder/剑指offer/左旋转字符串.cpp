class Solution {
public:
    void helper(string &s, int left, int right) {
    if (s.empty() || 1 == s.size() || left < 0 || size_t(left) >= s.size() || right < 0 || size_t(right) >= s.size() || left == right) { return; }

    char tmp;
    while (left < right) {
      tmp = s[left];
      s[left] = s[right];
      s[right] = tmp;

      ++left;
      --right;
    }
  }
    
    string LeftRotateString(string &str, int n) {
        if (str.empty() || 1 == str.size() || n <= 0) { return str; }
        
        helper(str, 0, str.size() - 1);
        helper(str, 0, str.size() - n - 1);
        helper(str, str.size() - n, str.size() - 1);
        return str;
    }
};
