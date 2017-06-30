
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:

  int coinChange(vector<int>& coins, int amount) {

    int rel = amount + 1;

    int n = coins.size();

    vector<vector<int>> marks(n+1, vector<int>(amount+1, INT_MAX));

    for(int i=0; i<=n; i++)
      marks[i][0] = 0;

    for(int i=1; i<=amount; i++)
      marks[0][i] = INT_MAX - 1;

    rel = recursive(marks, coins, coins.size(), amount);

    return rel;
  }


  int recursive(vector<vector<int>>& marks, vector<int>& coins, int num, int target) {

    if(target < 0)
      return INT_MAX - 1;

    if(marks[num][target] < INT_MAX)
      return marks[num][target];

    int one = recursive(marks, coins, num, target - coins[num-1]) + 1;

    int two = recursive(marks, coins, num-1, target);

    marks[num][target] = min(one, two);

    return marks[num][target];
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
