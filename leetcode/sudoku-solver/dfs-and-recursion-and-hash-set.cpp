class Solution {
public:
  Solution () {
    row = vector<unordered_set<char> >(9);
    clm = vector<unordered_set<char> >(9);
    blocks = vector<vector<unordered_set<char> > >(3, vector<unordered_set<char> >(3));
  }

  bool isValidToAdd(vector<vector<char> > &board, int i, int j, char c) {
    return row[i].find(c) == row[i].end() && clm[j].find(c) == clm[j].end()
      && blocks[i / 3][j / 3].find(c) == blocks[i / 3][j / 3].end();
  }

  bool helper(vector<vector<char> > &board){
    for (int i = 0; i < board.size(); ++i){
      for (int j = 0; j < board[i].size(); ++j){
        if ('.' != board[i][j]){ continue; }

        for (char c = '1'; c <= '9'; ++c){
          if (isValidToAdd(board, i, j, c)){
            board[i][j] = c;
            row[i].insert(c);
            clm[j].insert(c);
            blocks[i / 3][j / 3].insert(c);

            if (helper(board)){
              return true;
            }

            board[i][j] = '.';
            row[i].erase(c);
            clm[j].erase(c);
            blocks[i / 3][j / 3].erase(c);
          }
        }

        return false;
      }
    }

    return true;
  }

  void solveSudoku(vector<vector<char> > &board) {
    if (9 != board.size()){ return; }

    for (int i = 0; i < board.size(); ++i){
      if (9 != board[i].size()) { return; }

      for (int j = 0; j < board[i].size(); ++j){
        if ('.' == board[i][j]) {
          continue;
        }

        if (isValidToAdd(board, i, j, board[i][j])) {
          row[i].insert(board[i][j]);
          clm[j].insert(board[i][j]);
          blocks[i / 3][ j / 3].insert(board[i][j]);
        } else {
          return;
        }
      }
    }

    helper(board);
  }

  vector<unordered_set<char> > row, clm;
  vector<vector<unordered_set<char> > > blocks;
};
