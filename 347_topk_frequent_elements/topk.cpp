#include <iostream>
#include <vector>
#include <unordered_map>

#include <algorithm> // make_heap pop_heap


using namespace std;

class Solution {

public:

  // function object
  // overload () operator
  struct Comp {
    bool operator()(pair<int, int> one, pair<int, int> two) {
      return one.second < two.second;
    }
  };

  vector<int> topKFrequent(vector<int>& nums, int k) {

    vector<int> rel;

    unordered_map<int, int> counts;

    for(int n: nums) {
      auto search = counts.find(n);

      if(search == counts.end()) {
        counts[n] = 1;
      } else {
        counts[n] = counts[n] + 1;
      }
    }

    vector<pair<int, int>> numsCounts;

    for(auto it = counts.begin(); it != counts.end(); it++) {
      pair<int, int> t = make_pair(it->first, it->second);
      numsCounts.push_back(t);
    }

    make_heap(numsCounts.begin(), numsCounts.end(), Comp());

    for(int i = 0; i < k; i++) {

      // pop_heap move the largest number to pos [n-1]
      pop_heap(numsCounts.begin(), numsCounts.end(), Comp());
      pair<int, int> t = numsCounts.back();
      numsCounts.pop_back();

      rel.push_back(t.first);
    }

    return rel;

  }

};


void printVectors(vector<int> v) {

  for(int n: v) {
    cout<<n<<" ";
  }
  cout<<endl;

}

int main() {


  Solution demo = Solution();

  vector<int> rel;
  int k;

  vector<int> nums;

  nums.clear();
  nums.push_back(11);
  nums.push_back(11);
  nums.push_back(11);
  nums.push_back(12);
  nums.push_back(12);
  nums.push_back(13);
  k = 1;

  rel = demo.topKFrequent(nums, k);

  printVectors(rel);

}

