// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// You can return the answer in any order.
//
//
// Example 1:
//
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> result(2, 0);

    // build a map for O(1) lookup using O(n) space
    std::unordered_map<int, int> value_index_map;
    for (int i = 0; i < nums.size(); ++i) {
      value_index_map[nums[i]] = i;
    }

    // for loop the res value
    int res;
    for (int i = 0; i < nums.size(); ++i) {
      res = target - nums[i];
      const auto &iter = value_index_map.find(res);
      if (iter != value_index_map.end() && iter->second != i) {
        result[0] = i;
        result[1] = iter->second;
        break;
      }
    }
    return result;
  }
};

int main() {
  Solution demo = Solution();

  vector<int> input(3, 0);
  input[0] = 3;
  input[1] = 2;
  input[2] = 4;

  int target = 6;

  vector<int> rel = demo.twoSum(input, target);
  cout << "expect: " << 1 << " " << 2 << endl;
  cout << "output: " << rel[0] << " " << rel[1] << endl;
  return 0;
}
