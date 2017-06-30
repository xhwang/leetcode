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

    } else {

      for(size_t i = idx; i < candidates.size(); i++) {

        // hard part
        if(i > idx && candidates[i] == candidates[i-1])
          continue;

        curr.push_back(candidates[i]);
        recursive(rel, curr, candidates, i + 1, target - candidates[i]);
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



