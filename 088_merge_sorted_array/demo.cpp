#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

      int pos = m + n - 1;

      int lpos = m - 1;
      int rpos = n - 1;

      while (pos >= 0 && lpos >= 0 && rpos >= 0) {

        if (nums1[lpos] >= nums2[rpos]) {
          nums1[pos] = nums1[lpos];
          lpos--;
        }
        else {
          nums1[pos] = nums2[rpos];
          rpos--;
        }

        pos--;
      }

      while (pos >= 0) {
        nums1[pos--] = nums1[rpos--];
      }
    }
};


int main() {

  Solution demo = Solution();

  vector<int> nums1(20);
  nums1[0] = -1;
  nums1[1] = 0;
  nums1[2] = 0;
  nums1[3] = 3;
  nums1[4] = 3;
  nums1[5] = 3;

  vector<int> nums2 = {1, 2, 2};

  demo.merge(nums1, 6, nums2, 3);

  for (auto n: nums1)
    cout<<n<<" ";
  cout<<endl;

  return 0;
}
