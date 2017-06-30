#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    vector<vector<int>> rel;
    vector<int> curr;

    recursive(rel, curr, candidates, 0, target);

    return rel;

  }


  void recursive(vector<vector<int>>& rel, vector<int>& curr, const vector<int>& candidates, size_t idx, int target) {

    if(idx >= candidates.size() || target < 0)
      return;
  
    if(0 == target) {

      vector<int> t(curr);
      rel.push_back(t);

    } else {

      curr.push_back(candidates[idx]);
      recursive(rel, curr, candidates, idx, target - candidates[idx]);
      curr.pop_back();

      recursive(rel, curr, candidates, idx+1, target);
    
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

  vector<int> nums;
  int target;
  vector<vector<int>> rel;

  nums.clear();
  nums.push_back(7);
  nums.push_back(3);
  nums.push_back(6);
  nums.push_back(2);

  target = 7;
  rel = demo.combinationSum(nums, target);

  printVectors(rel);

  cout<<endl;

  // input nums should not have duplicated elements,
  // otherwise, the result are not unique.
  nums.clear();
  nums.push_back(10);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(7);
  nums.push_back(6);
  nums.push_back(1);
  nums.push_back(5);

  target = 8;
  rel = demo.combinationSum(nums, target);

  printVectors(rel);

}



