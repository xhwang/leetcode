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

    if(target < 0)
      return;
  
    if(0 == target) {

      vector<int> t(curr);
      rel.push_back(t);

    } else {

      for(size_t i = idx; i < candidates.size(); i++) {

        curr.push_back(candidates[i]);
        recursive(rel, curr, candidates, i, target - candidates[i]);
        curr.pop_back();

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

  vector<int> nums;
  int target;
  vector<vector<int>> rel;

  nums.clear();
  nums.push_back(7);
  nums.push_back(3);
  nums.push_back(5);
  nums.push_back(2);

  target = 7;
  rel = demo.combinationSum(nums, target);

  printVectors(rel);
  cout<<rel.size()<<endl;


  nums.clear();
  nums.push_back(186);
  nums.push_back(419);
  nums.push_back(83);
  nums.push_back(408);
  target = 6249;
  rel = demo.combinationSum(nums, target);

  printVectors(rel);

  size_t l = target;
  for(vector<int> v: rel) {
    if(v.size() < l)
      l = v.size();
  }
  cout<<l<<endl;

  /*
  // input should be unique, otherwise there are duplicate elements
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
  */

}



