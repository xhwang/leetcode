
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:

  int count;

  int coinChange(vector<int>& coins, int amount) {

    count = 0;

    int rel = amount + 1;

    // sort is necessary for pruning
    sort(coins.rbegin(), coins.rend());

    backtrace(rel, 0, coins, 0, amount);

    cout<<"number "<< coins.size() <<" amount "<<amount<<" function call "<<count<<endl;
  
    return rel == amount + 1 ? -1 : rel;
  }


  void backtrace(int& len, int cur, vector<int>& coins, int idx, int target) {

    count++;

    //cout<<idx<<" "<<target<<endl;
    //if(0 == target)
    //  cout<<"best "<<len<<" cur "<<cur<<endl;

    if(0 == target && cur < len) {
      len = cur;
      return;
    }

    for(size_t i=idx; i < coins.size(); i++) {

      int num = target / coins[i];

      //if(cur + num >= len)
      //  break;

      //j from big to small
      //for(int j = 1; j <= num; j++) {
      for(int j = num; j >= 1; j--) {
        backtrace(len, cur+j, coins, i+1, target - coins[i]*j);
      }

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
  cout<<endl;

  coins.clear();
  coins.push_back(16);
  coins.push_back(14);
  coins.push_back(3);
  amount = 27;
  rel = demo.coinChange(coins, amount);
  cout<<rel<<endl;
  cout<<endl;

  coins.clear();
  coins.push_back(186);
  coins.push_back(419);
  coins.push_back(83);
  coins.push_back(408);
  amount = 6249;
  rel = demo.coinChange(coins, amount);
  cout<<rel<<endl;
  cout<<endl;

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
  cout<<endl;


}
