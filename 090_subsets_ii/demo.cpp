
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

  public:

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

      vector<vector<int>> rel;
      vector<int> path;

      sort(nums.begin(), nums.end());

      bt(rel, path, nums, 0);

      return rel;
    }

    void bt(vector<vector<int>>& rel, vector<int>& path, vector<int>& nums, size_t idx) {
    
      if (idx > nums.size())
        return;

      rel.push_back(path);

      for (size_t i = idx; i < nums.size(); i++) {

        if (i > idx && nums[i] == nums[i-1])
          continue;

        path.push_back(nums[i]);
        bt(rel, path, nums, i+1);
        path.pop_back();
      }

    }

};


int main() {

  Solution demo = Solution();

  vector<int> nums = {1, 2, 2};

  vector<vector<int>> rel = demo.subsetsWithDup(nums);

  for (auto v:rel) {
    for (auto i: v) {
      cout<<i<<" ";
    }
    cout<<endl;
  }

}
