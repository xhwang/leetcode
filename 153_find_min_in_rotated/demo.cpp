#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int findMin(vector<int>& nums) {

      int low = 0;
      int high = nums.size() - 1;
      int mid;

      if (nums[low] < nums[high])
        return nums[low];

      while (low < high) {

        if (high - low == 1)
          break;

        mid = (low + high) / 2;

        if(nums[mid] > nums[low])
          low = mid;
        else 
          high = mid;

      }

      return nums[high];

    }


};


int main() {

  Solution demo = Solution();
  vector<int> nums = {3, 5, 6, 1, 2};
  cout<<demo.findMin(nums)<<endl;
  nums = {3, 5, 6, 1};
  cout<<demo.findMin(nums)<<endl;
  nums = {1, 2, 3, 5, 6};
  cout<<demo.findMin(nums)<<endl;
  nums = {1, 2};
  cout<<demo.findMin(nums)<<endl;
  nums = {2, 1};
  cout<<demo.findMin(nums)<<endl;
  return 0;
}
