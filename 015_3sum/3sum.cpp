#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:

  /* 
   * From discussion, k-sum problems have a bound of O(n^{ceil(k/2)})
   */
  vector<vector<int>> threeSum(vector<int>& nums) {

    vector<vector<int>> rel;
    if(nums.size() < 3)
      return rel;

    sort(nums.begin(), nums.end());

    for(size_t i=0;i<nums.size()-2;){

      // one iteration can find two sum in an ordered array
      int value = -nums[i];
      size_t low = i+1;
      size_t high = nums.size() - 1;

      while(low<high) {

        int temp = nums[low] + nums[high];
        if(temp < value)
          low++;
        else if(temp > value)
          high--;
        else {
          int values[] = {nums[i], nums[low], nums[high]};
          vector<int> t(values, values + 3);
          rel.push_back(t);
          
          do {
            low++;
          } while(nums[low-1]==nums[low]);

          do {
            high--;
          } while(nums[high+1]==nums[high]);
        }
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

  printVectors(rel);

}



