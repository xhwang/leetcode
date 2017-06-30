#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:

  vector<vector<int>> threeSum(vector<int>& nums) {

    vector<vector<int>> rel;
    vector<int> curr;

    sort(nums.begin(), nums.end());

    recursive(rel, curr, nums, 0, 0, 3);

    return rel;

  }


  void recursive(vector<vector<int>>& rel, vector<int>& curr, const vector<int>& candidates, size_t idx, int target, size_t num) {

    if(target < 0)
      return;
  
    if(0 == target && curr.size() == num) {

      vector<int> t(curr);
      rel.push_back(t);

    } else {

      for (size_t i=idx; i<candidates.size(); i++) {

        if(i > idx && candidates[i] == candidates[i-1])
          continue;

        if(curr.size() < num) {
          curr.push_back(candidates[i]);
          recursive(rel, curr, candidates, i+1, target - candidates[i], num);
          curr.pop_back();
        }

      }

    
    }
  
  
  }


};


void printVectors(vector<vector<int>> vectors) {

  for(vector<int> v: vectors) {
    for(int n: v) {
      cout<<n<<" ";
    }
    cout<<endl;
  }

}

int main() {


  Solution demo = Solution();

  vector<vector<int>> rel;

  vector<int> nums;
  nums.push_back(-1);
  nums.push_back(0);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(-1);
  nums.push_back(4);
  rel = demo.threeSum(nums);

  printVectors(rel);

}



