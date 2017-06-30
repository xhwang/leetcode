
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:

  int coinChange(vector<int>& coins, int amount) {

    int rel = -1;

    vector<int> path;

    sort(coins.rbegin(), coins.rend());

    backtrace(rel, path, coins, amount);
  
    return rel;
  }


  void backtrace(int& len, vector<int>& path, vector<int>& coins, int target) {

    if(0 > target)
      return;
  
    if(0 == target) {
      int l = path.size();
      if(-1 == len)
        len = l;
      else if(l < len)
        len = l;
      return;
    }

    int psize = path.size();
    if(-1 != len && psize > len)
      return;

    // backtrace 的关键是 i 从上一个节点开始的, 而不是根节点
    // 否则会产生重复计算
    // 所以参数应该加上当前的层数
    for(size_t i=0; i < coins.size(); i++) {

      path.push_back(coins[i]);
      backtrace(len, path, coins, target - coins[i]);
      path.pop_back();

    }
  
  }

};


int main() {


  Solution demo = Solution();

  vector<int> coins;
  int amount;
  int rel;

  coins.clear();
  coins.push_back(1);
  coins.push_back(2);
  coins.push_back(5);
  //amount = 100;
  amount = 11;
  rel = demo.coinChange(coins, amount);
  cout<<rel<<endl;

  coins.clear();
  coins.push_back(16);
  coins.push_back(14);
  coins.push_back(3);
  amount = 27;
  rel = demo.coinChange(coins, amount);
  cout<<rel<<endl;

  coins.clear();
  coins.push_back(186);
  coins.push_back(419);
  coins.push_back(83);
  coins.push_back(408);
  amount = 6249;
  rel = demo.coinChange(coins, amount);
  cout<<rel<<endl;
}
