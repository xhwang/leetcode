// You are given an integer array height of length n. 
// There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

// Note: exceed time limit
//   int maxArea(vector<int>& height) {
//     int max_area = 0;
//     int h, area;
//     for (int i = 0; i < height.size() - 1; ++i) {
//       for (int j = i + 1; j < height.size(); ++j) {
//         h = min(height[i], height[j]);
//         area = (j - i) * h;
//         if (area > max_area) {
//           max_area = area;
//         }
//       }
//     }
//     return max_area;
//   }

  int maxArea(vector<int>& height) {
    int max_area = 0;
    int start = 0;
    int end = height.size() - 1;
    int h, area;

    // two pointer method
    // if inner area > outer area
    // inner height must > outer height
    while (end > start) {
      h = min(height[start], height[end]);
      area = (end - start) * h;
      if (area > max_area) {
        max_area = area;
      }

      if (height[start] < height[end]) {
        int t = start + 1;
        while (height[start] > height[t]) {
          ++t;
        }
        start = t;
      } else if (height[start] > height[end]) {
        int t = end - 1;
        while (height[end] > height[t]) {
          --t;
        }
        end = t;
      } else {
        ++start;
        --end;
      }
    }

    return max_area;
  }
};

int main() {
  Solution demo = Solution();

  // vector<int> heights = {1,8,6,2,5,4,8,3,7};
  // cout << "expect: " << "49" << " actual: " << demo.maxArea(heights) << endl;

  vector<int> heights;
  heights[5] = 0;

  return 0;
}
