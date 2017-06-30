#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {

public:

  int minPathSum(vector<vector<int>>& grid) {

    int row = grid.size();
    if(0 == row)
      return 0;
    int col = grid[0].size();

    vector<vector<int>> cost(row, vector<int>(col, 0));

    cost[0][0] = grid[0][0];

    for(int c = 1; c < col; c++) {
      cost[0][c] = grid[0][c] + cost[0][c-1];
    }

    for(int r = 1; r < row; r++) {
      cost[r][0] = grid[r][0] + cost[r-1][0];
    }

    for(int r = 1; r < row; r++) {
      for(int c = 1; c < col; c++) {
        cost[r][c] = grid[r][c] + min(cost[r][c-1], cost[r-1][c]);
      }
    }

    return cost[row-1][col-1];

  }

};


int main() {


  Solution demo = Solution();

  vector<vector<int>> nums = {
    {1, 2, 3},
    {4, 5, 6},
  };

  int rel;
  rel = demo.minPathSum(nums);
  cout<<"rel:"<<rel<<endl;

}


