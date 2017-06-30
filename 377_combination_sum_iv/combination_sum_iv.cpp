#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {

public:

  int combinationSum4(vector<int>& nums, int target) {
    int count = 0;

    // initialization value can not be 0, as there may be values[target] = 0,
    // which makes it ambiguous whether is no solution or not calculated. 
    vector<int> values(target+1, -1);
    values[0] = 1;

    count = combinationIndex(nums, target, values);

    return count;

  }

  // 备忘录算法, 只需要求解必要的
  int combinationIndex(vector<int>& nums, int target, vector<int>& values) {

    if(values[target] == -1) {

      int count = 0;
      for(size_t i = 0; i < nums.size(); i++) {
        if(target - nums[i] >= 0) {
          count += combinationIndex(nums, target - nums[i], values);
        }
      }

      values[target] = count;
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


