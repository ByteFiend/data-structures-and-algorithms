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

  void trim(string &s) {
    if (s.empty()) { return; }

    int left = 0, right = s.size() - 1;
    while (left <= right) {
      if (' ' != s[left]) { break; }
      ++left;
    }
    while (left <= right) {
      if (' ' != s[right]) { break; }
      --right;
    }

    if (left > right) {
      s.clear();
      return;
    }

    s[0] = s[left];
    int idxNew = 1, idxOld = left + 1;
    for (; idxOld <= right; ++idxOld) {
      if (' ' == s[idxOld] && ' ' == s[idxOld - 1]) { continue; }
      s[idxNew++] = s[idxOld];
    }
    s.resize(idxNew);
  }

  void reverseWords(string &s) {
    trim(s);
    if (s.empty() || 1 == s.size()) { return; }

    helper(s, 0, s.size() - 1);

    int left = 0, right = s.size() - 1;
    while (left <= right) {
      int begin = left, end = left;
      while (end <= right && ' ' != s[end]) { ++end; }
      helper(s, begin, end - 1);
      left = end + 1;
    }
  }
};
