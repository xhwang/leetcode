#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:

  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

    vector<vector<int>> rel;
    vector<int> curr;

    sort(candidates.begin(), candidates.end());

    recursive(rel, curr, candidates, 0, target);

    return rel;

  }


  void recursive(vector<vector<int>>& rel, vector<int>& curr, const vector<int>& candidates, size_t idx, int target) {

    if(target < 0)
      return;
  
    if(0 == target) {

      vector<int> t(curr);
      rel.push_back(t);

    } else if(idx < candidates.size()) {

      int value = candidates[idx];
      size_t nidx = idx;
      while(nidx + 1 < candidates.size() && candidates[nidx+1] == value) {
        nidx = nidx + 1;
      }

      for(size_t i = 1; i <= nidx - idx + 1; i++) {

        for(size_t j = 1; j <= i; j++)
          curr.push_back(candidates[idx]);

        recursive(rel, curr, candidates, nidx + 1, target - candidates[idx] * i);

        for(size_t j = 1; j <= i; j++)
          curr.pop_back();

      }
      recursive(rel, curr, candidates, nidx + 1, target);
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
  nums.push_back(10);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(7);
  nums.push_back(6);
  nums.push_back(1);
  nums.push_back(5);

  int target;
  vector<vector<int>> rel;

  target = 8;
  rel = demo.combinationSum2(nums, target);

  printVectors(rel);

}



