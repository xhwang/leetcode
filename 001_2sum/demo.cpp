
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

  public:
    vector<int> twoSum(vector<int> &nums, int target) {

      vector<int> rel(2);

      // initial value '0'
      // cout<<rel[0]<<" "<<rel[1]<<endl;

      unordered_map<int, int> nums_map;
      int res;

      for(unsigned int i=0; i<nums.size(); i++) {
        //nums_map.insert({nums[i], i});
        nums_map[nums[i]] = i;
      }

      for(unsigned int i=0; i<nums.size(); i++) {
        res = target - nums[i];

        auto search = nums_map.find(res);

        if(search != nums_map.end() && search->second != (int)i) {

          rel[0] = i;
          rel[1] = search->second;
          break;

        }

      }


      return rel;
    }


};


int main() {

  Solution demo = Solution();

  // if no 10, there is no capacity
  vector<int> input(10);

  input[0] = 3;
  input[1] = 2;
  input[2] = 4;

  input.resize(3);

  int target = 6;

  vector<int> rel = demo.twoSum(input, target);
  cout<<rel[0]<<" "<<rel[1]<<endl;

}


