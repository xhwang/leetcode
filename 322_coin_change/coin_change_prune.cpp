
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:

  int coinChange(vector<int>& coins, int amount) {

    count = 0;

    sort(coins.rbegin(), coins.rend());

    int cur = 0;
    int mcur = amount + 1;

    backtrace(coins, 0, amount, cur, mcur);

    if(mcur == amount + 1)
      mcur = -1;

    cout<<"number "<< coins.size() <<" amount "<<amount<<" function call "<<count<<endl;
  
    return mcur;
  }


  void backtrace(vector<int>& coins, size_t idx, int target, int cur, int& mcur) {

    count++;

    if(target == 0 && cur < mcur)
      mcur = cur;

    if(idx >= coins.size())
      return;

    int num = target / coins[idx];


    // 注意是从大往小降, 这样剪枝效果比相反的好
    // 因为如果i已经不是最优, i-k 一定至少需要 k 个元素才能使和为 target
    //for(int i=0; i<=n; i++) {
    for(int i=num; i>=0; i--) {

      int ntarget = target - coins[idx] * i;
      int ncur = cur + i;

      // used for pruning
      if(ncur > mcur)
        break;

      backtrace(coins, idx+1, ntarget, ncur, mcur);

    }

  }

  int count;

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
  coins.push_back(186);
  coins.push_back(419);
  coins.push_back(83);
  coins.push_back(408);
  amount = 6249;
  rel = demo.coinChange(coins, amount);
  cout<<rel<<endl;

  coins.clear();
  coins.push_back(3);
  coins.push_back(7);
  coins.push_back(405);
  coins.push_back(436);
  amount = 8839;
  rel = demo.coinChange(coins, amount);
  cout<<rel<<endl;

  coins.clear();
  coins.push_back(3);
  coins.push_back(16);
  coins.push_back(14);
  amount = 27;
  rel = demo.coinChange(coins, amount);
  cout<<rel<<endl;
}
