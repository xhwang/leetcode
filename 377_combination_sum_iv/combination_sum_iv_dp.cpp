#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {

public:

  int combinationSum4(vector<int>& nums, int target) {

    vector<int> values(target+1, 0);

    values[0] = 1;

    for(int t = 1; t <= target; t++) {
      for(size_t i = 0; i < nums.size(); i++) {
        if(t-nums[i]>=0)
          values[t] += values[t-nums[i]];
      }
    }

    return values[target];

  }

};


int main() {


  Solution demo = Solution();

  vector<int> nums;

  int target;
  int rel;

  nums.clear();
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(4);
  target = 32;

  rel = demo.combinationSum4(nums, target);
  cout<<"rel:"<<rel<<endl;

  nums.clear();
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  target = 4;

  rel = demo.combinationSum4(nums, target);
  cout<<"rel:"<<rel<<endl;
}


