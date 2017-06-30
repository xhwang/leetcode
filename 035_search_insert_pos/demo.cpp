#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int searchInsert(vector<int>& nums, int target) {

      int start = 0;
      int end = nums.size() - 1;
      int mid;

      if (nums.size() == 0)
        return 0;

      if (target > nums[end])
        return end+1;
       
      while(start<=end) {
      
        mid = (start + end) / 2;

        if (target == nums[mid]) 
          return mid;
        else if (target < nums[mid])
          end = mid - 1;
        else
          start = mid + 1;
      }

      // TODO: start is the POSITION
      return start;
    }


    int searchInsertRecursive(vector<int>& nums, int target) {
      return recursive(nums, 0, nums.size()-1, target);
    }


    int  recursive(vector<int>& nums, int start, int end, int target) {
      if (start > end)
        return start;

      int mid = (start + end) / 2;

      if (target == nums[mid])
        return mid;
      else if (target < nums[mid])
        return recursive(nums, start, mid-1, target);
      else
        return recursive(nums, mid+1, end, target);
    }
};


int main() {

  Solution demo = Solution();
  vector<int> nums = {1, 3, 5, 6};
  int target;
  target = 5;
  cout<<target<<" "<<demo.searchInsert(nums, target)<<endl;
  target = 2;
  cout<<target<<" "<<demo.searchInsert(nums, target)<<endl;
  target = 7;
  cout<<target<<" "<<demo.searchInsert(nums, target)<<endl;
  target = 0;
  cout<<target<<" "<<demo.searchInsert(nums, target)<<endl;
  return 0;
}
