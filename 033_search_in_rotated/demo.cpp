#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int search(vector<int>& nums, int target) {

      int low = 0;
      int high = nums.size() - 1;
      int mid;

      while (low <= high) {
	
	      //TODO: mid target compare not correct
        
        mid = (low + high) / 2;

        if (nums[mid] > nums[high]) {
        

        }
        

      }

      return -1;

    }


};


int main() {

  Solution demo = Solution();
  int target;
  vector<int> nums = {3, 5, 6, 1, 2};
  target = 3;
  cout<<demo.search(nums, target)<<endl;
  target = 4;
  cout<<demo.search(nums, target)<<endl;
  target = 2;
  cout<<demo.search(nums, target)<<endl;
  return 0;
}
