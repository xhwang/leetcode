#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {

public:

  /* 
   * From discussion, k-sum problems have a bound of O(n^{ceil(k/2)})
   */
  vector<vector<int>> threeSum(vector<int>& nums) {

    vector<vector<int>> rel;
    vector<int> curr;

    sort(nums.begin(), nums.end());

    unordered_map<int, size_t> maps;

    for(size_t i=0;i<nums.size();i++) {
      maps[nums[i]] = i;
    }

    for(size_t i=0;i<nums.size()-2;){
      cout<<"i "<<i<<"value "<<nums[i]<<endl;

      for(size_t j=i+1;j<nums.size()-1;){
        cout<<"j "<<j<<"value "<<nums[j]<<endl;
    
        int value = -(nums[i] + nums[j]);
        
        auto found = maps.find(value);
        if(found != maps.end() && found->second > j) {
        
          vector<int> t;
          t.push_back(nums[i]);
          t.push_back(nums[j]);
          t.push_back(value);
          rel.push_back(t);
        
          cout<<nums[i]<<" "<<nums[j]<<" "<<value<<endl;
        }

        do {
          j++;
        } while(nums[j-1]==nums[j]);
      }

      do {
        i++;
      } while(nums[i-1]==nums[i]);
    }


    return rel;

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

  //printVectors(rel);

}



