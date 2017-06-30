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

    vector<int> rel = {0, 0};

    int mis = 0;
    for(int n: nums)
      mis ^= n;

    // find the value which only the last none-zero bit of `mis` is non-zero.
    int mask = mis & (-mis);

    for(int n: nums) {

      // 之前使用 if-else, 基本逻辑是 =0, 与num1异或, !=0 与num2 异或
      // 转化为直接给0, 1赋值 !!!
      rel[!(n&mask)] ^= n;
    }
    return rel;

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



