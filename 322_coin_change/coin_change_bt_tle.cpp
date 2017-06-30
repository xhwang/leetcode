
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:

  int coinChange(vector<int>& coins, int amount) {

    int rel = amount + 1;

    vector<int> path;

    sort(coins.rbegin(), coins.rend());

    backtrace(rel, path, coins, 0, amount);
  
    return rel == amount + 1 ? -1 : rel;
  }


  void backtrace(int& len, vector<int>& path, vector<int>& coins, int idx, int target) {

    if(0 > target)
      return;
  
    if(0 == target) {
      int l = path.size();
      if(l < len)
        len = l;
      return;
    }

    int psize = path.size();
    if(-1 != len && psize > len)
      return;

    for(size_t i=idx; i < coins.size(); i++) {

      path.push_back(coins[i]);
      backtrace(len, path, coins, i, target - coins[i]);
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

  coins.clear();
  coins.push_back(288);
  coins.push_back(160);
  coins.push_back(10);
  coins.push_back(249);
  coins.push_back(40);
  coins.push_back(77);
  coins.push_back(314);
  coins.push_back(429);
  amount = 9208;
  rel = demo.coinChange(coins, amount);
  cout<<rel<<endl;


}
