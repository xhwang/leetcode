#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:

  /*
   * clockwise rotate
   * first reverse up to down, then swap the symmetry 
   * 1 2 3     7 8 9     7 4 1
   * 4 5 6  => 4 5 6  => 8 5 2
   * 7 8 9     1 2 3     9 6 3
  */
  void rotate(vector<vector<int>>& matrix) {

    reverse(matrix.begin(), matrix.end());

    int n = matrix.size();
    for(int i = 1; i < n; i++) {
      for(int j = 0; j < i; j++) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }

  }

  /*
   * anticlockwise rotate
   * first reverse left to right, then swap the symmetry
   * 1 2 3     3 2 1     3 6 9
   * 4 5 6  => 6 5 4  => 2 5 8
   * 7 8 9     9 8 7     1 4 7
  */
  void anti_rotate(vector<vector<int>> &matrix) {

    for(auto& vi : matrix) 
      reverse(vi.begin(), vi.end());

    int n = matrix.size();
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j)
        swap(matrix[i][j], matrix[j][i]);
    }
  }


};


void printMatrix(vector<vector<int>>& matrix) {

  for(vector<int> row: matrix) {
    for(int e: row)
      cout<<e<<" ";
    cout<<endl;
  }
  cout<<endl;

}

int main() {

  Solution demo = Solution();
  vector<vector<int>> matrix = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };

  printMatrix(matrix);

  demo.rotate(matrix);
  printMatrix(matrix);

  demo.anti_rotate(matrix);
  printMatrix(matrix);

  return 0;
}
