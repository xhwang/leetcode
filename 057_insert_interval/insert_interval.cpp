#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      vector<vector<int>> rel;
      if (intervals.size() == 0) {
          rel.push_back(newInterval);
          return rel;
      }

      int start, end;

      int left = newInterval[0];
      int right = newInterval[1];

      int l_index = -1;
      int r_index = -1;

      bool l_inside = false;
      bool r_inside = false;

      start = 0;
      end = intervals.size() - 1;
      do {
          int mid = (start + end ) / 2;
          if (left > intervals[mid][1]) {
              start = mid + 1;
          } else if (left >= intervals[mid][0]) {
              l_index = mid;
              l_inside = true;
              break;
          } else {
              end = mid - 1;
          }
      } while (end >=0 && start < intervals.size() && start <= end);
      if (!l_inside) {
          l_index = start;
      }
      cout << l_index << endl;

      start = 0;
      end = intervals.size() - 1;
      do {
          int mid = (start + end ) / 2;
          if (right > intervals[mid][1]) {
              start = mid + 1;
          } else if (right >= intervals[mid][0]) {
              r_index = mid;
              r_inside = true;
              break;
          } else {
              end = mid - 1;
          }
      } while (end >=0 && start < intervals.size() && start <= end);
      if (!r_inside) {
          r_index = start - 1;
      }
      cout << r_index << endl;

      if (l_inside) {
          left = intervals[l_index][0];
      } else {
          left = newInterval[0];
      }

      if (r_inside) {
          right = intervals[r_index][1];
      } else {
          right = newInterval[1];
      }

      for (int i = 0; i < l_index; ++i) {
          rel.push_back(intervals[i]);
      }
      rel.push_back({left, right});
      for (int i = r_index + 1; i < intervals.size(); ++i) {
          rel.push_back(intervals[i]);
      }

      return rel;
  }
};

int main() {
  Solution demo = Solution();

  vector<vector<int>> s = {{1,3},{6,9}};
  vector<int> newInterval = {2,5};
  demo.insert(s, newInterval);

  return 0;
}
