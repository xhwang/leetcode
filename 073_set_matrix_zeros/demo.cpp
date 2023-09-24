
#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>>& matrix);

class Solution {

  public:
    void setZeroes(vector<vector<int>>& matrix) {
    
      int m = matrix.size();
      if (m == 0)
        return;
      int n = matrix[0].size();
      if (n == 0)
        return;

      int col = 1;

      for (int i=0; i<m; i++) {
        if (matrix[i][0] == 0)
          col = 0;
        for (int j=1; j<n; j++) {
          if (matrix[i][j] == 0) {
            matrix[i][0] = 0;
            matrix[0][j] = 0;
          }
        }
      }

      cout<<col<<endl;
      printMatrix(matrix);

      for (int i=m-1; i>=0; i--) {
        for (int j=n-1; j>=1; j--) {
          if (matrix[i][0] == 0 || matrix[0][j] == 0)
            matrix[i][j] = 0;
        }
        if (col == 0)
          matrix[i][0] = 0;
      }

    }

};

void printMatrix(vector<vector<int>>& matrix) {

  int m = matrix.size();
  int n = matrix[0].size();
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
}


int main() {

  Solution demo = Solution();
  vector<vector<int>> matrix = {{1,1,1,1,0}, {1,1,1,1,0}, {1,1,1,1,1}};
  demo.setZeroes(matrix);

  cout<<"done"<<endl;
}
