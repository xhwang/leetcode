#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:

  vector<vector<int>> combinationSum3(int k, int n) {

    vector<vector<int>> rel;
    vector<int> curr;
    int narray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> candidates(narray, narray + sizeof narray / sizeof narray[0]);

    recursive(rel, curr, candidates, 0, k, n);

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

  int target;
  int num;
  vector<vector<int>> rel;

  target = 9;
  num = 3;
  rel = demo.combinationSum3(target, num);

  printVectors(rel);

  cout<<endl;

  target = 88;
  num = 4;
  rel = demo.combinationSum3(target, num);

  printVectors(rel);

}



