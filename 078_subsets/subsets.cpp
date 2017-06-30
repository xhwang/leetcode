#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:

  vector<vector<int>> subsets(vector<int>& nums) {

    vector<vector<int>> rel;
    vector<int> curr;

    recursive(rel, curr, nums, 0);

    return rel;

  }


  void recursive(vector<vector<int>>& rel, vector<int>& curr, 
    const vector<int>& nums, size_t idx) {

    vector<int> t(curr);
    rel.push_back(t);

    for(size_t i = idx; i < nums.size(); i++) {

      curr.push_back(nums[i]);
      recursive(rel, curr, nums, i+1);
      curr.pop_back();

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
  vector<vector<int>> rel;

  nums.clear();
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(2);

  rel = demo.subsets(nums);

  printVectors(rel);
  cout<<rel.size()<<endl;


}



