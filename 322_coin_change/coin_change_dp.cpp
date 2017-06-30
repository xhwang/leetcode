
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:

  int coinChange(vector<int>& coins, int amount) {

    int n = coins.size();

    vector<int> marks(amount + 1, amount + 1);

    marks[0] = 0;

    for(int i = 1; i <= amount; i++) {
    
      for(int j = 0; j < n; j++) {

        if(i >= coins[j])
          marks[i] = min(marks[i], marks[i-coins[j]]+1);
      }

    }

    return marks[amount] == amount + 1 ? -1 : marks[amount];
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
}
