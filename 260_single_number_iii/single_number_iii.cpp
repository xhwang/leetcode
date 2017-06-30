#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVectors(vector<int>& nums);

class Solution {

public:


  //http://blog.csdn.net/morewindows/article/details/7354571
  //bit operation summary
  vector<int> singleNumber(vector<int>& nums) {

    vector<int> rel;

    int mis = 0;
    for(int n: nums)
      mis ^= n;

    int pos = findFirstNoneZero(mis);

    vector<int> one;
    vector<int> two;

    for(int n: nums) {
      if( n>>pos & 1 ) {
        one.push_back(n);
      } else {
        two.push_back(n);
      }
    }

    rel.push_back(findSingle(one));
    rel.push_back(findSingle(two));

    return rel;

  }

  int findSingle(vector<int>& nums) {
    int rel = 0;
    for(int n: nums) {
      rel ^= n;
    }
    return rel;
  }

  /* find first no zero in binary 
   * return: pos, 0 index
   */
  int findFirstNoneZero(int n) {
    int i=0;
    while(!(n&1)) {
      i++;
      n = n>>1;
    }
    return i;
  }

};


void printVectors(vector<int>& v) {

  for(int n: v) {
    cout<<n<<" ";
  }
  cout<<endl;

}

int main() {


  Solution demo = Solution();

  vector<int> rel;

  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(2);
  nums.push_back(5);
  rel = demo.singleNumber(nums);

  cout<<endl;

  printVectors(rel);

}



