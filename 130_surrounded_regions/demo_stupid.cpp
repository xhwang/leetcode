
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

  public:

    void solve(vector<vector<char>>& board) {

      int m = board.size();
      if (m < 0)
        return;
      int n = board[0].size();
      if (n < 0)
        return;

      int** mark = new int*[m];
      for(int i=0; i<m; i++) {
        mark[i] = new int[n];
      }

      for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
          mark[i][j] = 0;
        }
      }

      for (int i=0; i<m; i++) {
        if (board[i][0] == 'O')
          dfs(board, mark, m, n, i, 0);
        if (board[i][n-1] == 'O')
          dfs(board, mark, m, n, i, n-1);
      }

      for (int i=0; i<n; i++) {
        if (board[0][i] == 'O')
          dfs(board, mark, m, n, 0, i);
        if (board[m-1][i] == 'O')
          dfs(board, mark, m, n, m-1, i);
      }

      for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
          if (board[i][j] == 'O')
            board[i][j] = 'X';
          if (board[i][j] == 'B')
            board[i][j] = 'O';
        }
      }

    }


    void dfs(vector<vector<char>>& board, int** mark, int m, int n, int r, int c) {
    
      // 实际不用 mark, 访问的时候已经修改了元素, 在上层中不可能再访问到.

      board[r][c] = 'B';
      mark[r][c] = 1;

      if (r > 0 && mark[r-1][c] != 1 && board[r-1][c] == 'O')
        dfs(board, mark, m, n, r-1, c);
      if (r < m-1 && mark[r+1][c] != 1 && board[r+1][c] == 'O')
        dfs(board, mark, m, n, r+1, c);
      if (c > 0 && mark[r][c-1] != 1 && board[r][c-1] == 'O')
        dfs(board, mark, m, n, r, c-1);
      if (c < n-1 && mark[r][c+1] != 1 && board[r][c+1] == 'O')
        dfs(board, mark, m, n, r, c+1);
    }

};


void printMatrix(vector<vector<char>>& board) {

  int m = board.size();
  int n = board[0].size();

  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}


int main() {

  Solution demo = Solution();

  vector<vector<char>> board;

  vector<char> row;
  row = {'X', 'X', 'X', 'X'};
  board.push_back(row);
  row = {'X', 'O', 'O', 'X'};
  board.push_back(row);
  row = {'X', 'X', 'O', 'X'};
  board.push_back(row);
  row = {'X', 'O', 'X', 'X'};
  board.push_back(row);

  printMatrix(board);
  demo.solve(board);
  printMatrix(board);

}
