class Solution {
public:
  int dfs(int row, int size, int ans) {
    if (size <= 0 || row < 0) { return 0; }
    if (row == size) { return ans + 1; }

    for (int j = 0; j < size; ++j){
      if (clm.find(j) != clm.end() || x_minas_y.find(row - j) != x_minas_y.end() || x_add_y.find(row + j) != x_add_y.end()) {
        continue;
      }

      clm.insert(j);
      x_minas_y.insert(row - j);
      x_add_y.insert(row + j);

      ans = dfs(row + 1, size, ans);

      clm.erase(j);
      x_minas_y.erase(row - j);
      x_add_y.erase(row + j);
    }

    return ans;
  }

  int totalNQueens(int n) {
    int ans = 0;
    if (n <= 0) { return ans; }

    return dfs(0, n, ans);
  }

  unordered_set<int> clm, x_minas_y, x_add_y;
};
