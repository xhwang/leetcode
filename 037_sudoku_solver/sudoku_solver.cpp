
#include <iostream>
#include <vector>

using namespace std;


class Solution {

public:

  void solveSudoku(vector<vector<char>>& board) {

    vector<pair<int,int>> spaces;

    for(int i=0; i<9; i++) {
      for(int j=0; j<9; j++) {
        if(board[i][j] == '.') {
          pair<int, int> t = make_pair(i, j);
          spaces.push_back(t);
        }
      }
    }

    bt(board, spaces, 0);

  }


  bool bt(vector<vector<char>>& board, vector<pair<int, int>>& spaces, size_t idx) {

    if(idx >= spaces.size())
      return true;

    bool rel = false;

    pair<int, int> t = spaces[idx];
    int i = t.first;
    int j = t.second;

    for(int k = 1; k <= 9; k++) {
    
      if(isValid(board, i, j, k)) {
        board[i][j] = k + '0';
        rel = bt(board, spaces, idx+1);

        if(rel) {
          rel = true;
          break;
        }
        else {
          board[i][j] = '.';
        }
      }
    
    }

    return rel;

  }


  bool isValid(vector<vector<char>>& board, int i, int j, int value) {

    bool rel = true;

    for(int k = 0; k < 9; k++) {
      if(board[i][k] == value + '0')
        return false;
      if(board[k][j] == value + '0')
        return false;
    }

    int row = (i/3) * 3;
    int col = (j/3) * 3;

    for(int m=row; m<row+3; m++) {
      for(int n=col; n<col+3; n++) {
        if(board[m][n] == value + '0')
          return false;
      }
    }

    return rel;
  }

};

void printMatrix(vector<vector<char>>& board) {

  for(vector<char> row: board) {
    for(char c: row) {
      cout<<c<<" ";
    }
    cout<<endl;
  
  }

  cout<<endl;

}

void constructMatrix(vector<string> input, vector<vector<char>>& output) {

  for(int i=0; i<9;i++) {
    for(int j=0; j<9;j++) {
      output[i][j] = input[i][j];
    }
  }


}


int main() {

  Solution demo = Solution();

  vector<vector<char>> board(9, vector<char>(9, '.'));

  vector<string> input = {
    //"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."
    "..56.73..", ".4...1.7.", "...4....8", "...7..61.", "....2....", ".82..4...", "2....9...", ".9.8...4.", "..63.29.."
  };

  constructMatrix(input, board);

  printMatrix(board);

  demo.solveSudoku(board);

  printMatrix(board);

}


