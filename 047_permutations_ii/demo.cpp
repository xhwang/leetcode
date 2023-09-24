
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

  public:

    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> rel;
      vector<int> path;

      sort(nums.begin(), nums.end());
      vector<int> used(nums.size(), 0);

      helper(rel, path, nums, used);

      return rel;
    }

    void helper(vector<vector<int>>& rel, vector<int>& path, vector<int>& nums, vector<int> used) {
    
      if (path.size() == nums.size()) {
        rel.push_back(path);
        return;
      }

      for (size_t i=0; i<nums.size(); i++) {

        if (used[i] == 1)
          continue;

        // Note: used[i-1] is important
        // It restrict the first one of the same numbers should be used.
        if (i > 0 && nums[i-1] == nums[i] && used[i-1] == 0)
          continue;

        path.push_back(nums[i]);
        used[i] = 1;
        helper(rel, path, nums, used);
        path.pop_back();
        used[i] = 0;

      }

    }

};


int main() {

  Solution demo = Solution();

  vector<int> nums = {1, 1, 2};
  vector<vector<int>> rel = demo.permuteUnique(nums);
  cout<<rel.size()<<endl;

}
