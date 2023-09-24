
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

      helper(rel, path, nums);
      return rel;

    }


    void helper(vector<vector<int>>& rel, vector<int>& path, vector<int>& nums) {
    
      if (0 == nums.size())
        rel.push_back(path);

      for (size_t i=0; i<nums.size(); i++) {

        if (i == 0 || (i > 0 && nums[i-1] != nums[i])) {
          int value = nums[i];

          path.push_back(value);
          nums.erase(nums.begin()+i);

          helper(rel, path, nums);

          nums.insert(nums.begin()+i, value);
          path.pop_back();
        }

      }

    }

};


int main() {

  Solution demo = Solution();

  vector<int> nums = {1, 1, 2};
  vector<vector<int>> rel = demo.permuteUnique(nums);
  cout<<rel.size()<<endl;

}
