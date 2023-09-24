
#include <iostream>
#include <vector>

using namespace std;

class Solution {

  public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

      int m = obstacleGrid.size();
      if (m == 0)
        return 0;
      int n = obstacleGrid[0].size();
        
      vector<vector<int>> mark(m, vector<int>(n, 0));

      mark[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;

      for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {

          if (i == 0 && j == 0)
            continue;
          else if (i == 0) {
            mark[i][j] = obstacleGrid[i][j] == 0 ? mark[i][j-1] : 0;
          }
          else if (j == 0) {
            mark[i][j] = obstacleGrid[i][j] == 0 ? mark[i-1][j] : 0;
          }
          else {
            mark[i][j] = obstacleGrid[i][j] == 0 ? mark[i-1][j] + mark[i][j-1] : 0;
          }
        }
      }

      return mark[m-1][n-1];
    }


};


int main() {

  Solution demo = Solution();

  vector<vector<int>> obstacleGrid(3, vector<int>(3, 0));
  obstacleGrid[1][1] = 1;

  int rel = demo.uniquePathsWithObstacles(obstacleGrid);
  cout<<rel<<endl;

}
