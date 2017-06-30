
#include <iostream>
#include <vector>

using namespace std;

class Solution {

  public:

    // time complexity: O(mn), space complexity: O(max(m,n)) stack space

    int numIslands(vector<vector<char>>& grid) {

      int rel = 0;

      size_t row = grid.size();

      if(0 == row)
        return 0;

      size_t col = grid[0].size();

      // Actually, if there is no limits for input unchangable,
      // it is not necessary to allocate another matrix.
      // Just mark visit position to another value
      vector<vector<int>> mark(row, vector<int>(col, 0));

      for(size_t i = 0; i < row; i++) {
        for(size_t j = 0; j < col; j++) {

          if(grid[i][j] == '1' && mark[i][j] == 0) {
            rel = rel + 1;
            spread(i, j, grid, mark);
          }
        
        }

      }


      return rel;
    }

  private:

    void spread(int ri, int cj,
        vector<vector<char>>& grid,  
        vector<vector<int>>& mark) {

      /*
      // not decoupled, the function assume that call function do some check
      // check in the front of function decouple itself with its caller.
      mark[ri][cj] = 1;

      // left, right, up, and down are all necessary
      if(ri >= 1 && grid[ri-1][cj] == '1' && mark[ri-1][cj] == 0)
        spread(ri-1, cj, grid, mark);

      if(ri + 1 < mark.size() && grid[ri+1][cj] == '1' && mark[ri+1][cj] == 0)
        spread(ri+1, cj, grid, mark);
    
      if(cj >= 1 && grid[ri][cj-1] == '1' && mark[ri][cj-1] == 0)
        spread(ri, cj-1, grid, mark);

      if(cj + 1 < mark[0].size() && grid[ri][cj+1] == '1' && mark[ri][cj+1] == 0)
        spread(ri, cj+1, grid, mark);
      */

      int row = grid.size();
      int col = grid[0].size();

      if(ri<0 || ri>=row || cj<0 || cj>=col)
        return;

      if(grid[ri][cj] == '1' && mark[ri][cj] == 0) {

        mark[ri][cj] = 1;

        spread(ri-1, cj, grid, mark);
        spread(ri+1, cj, grid, mark);
        spread(ri, cj-1, grid, mark);
        spread(ri, cj+1, grid, mark);
      
      }

    
    }

};


int main() {

  Solution demo = Solution();

  vector< vector<char> > input{ 
          {'1', '1', '0', '0', '0'},
          {'1', '1', '0', '0', '0'},
          {'0', '0', '1', '0', '0'},
          {'1', '1', '0', '0', '0'},
  };

  int rel = demo.numIslands(input);
  cout<<rel<<endl;

  vector< vector<char> > input1{
          {'1', '1', '1'},
          {'0', '1', '0'},
          {'1', '1', '1'}
  };

  int rel1 = demo.numIslands(input1);
  cout<<rel1<<endl;
}


