
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:

  int coinChange(vector<int>& coins, int amount) {

    int rel = -1;

    int n = coins.size();

    vector<vector<int>> marks(n+1, vector<int>(amount+1, -2));

    marks[0][0] = 0;

    for(int i=1; i<=amount; i++) {
      marks[0][i] = -1;
    }

    for(int i=1; i<=n; i++)
      marks[i][0] = 0;

    rel = recursive(marks, coins, coins.size(), amount);

    return rel;
  }


  int recursive(vector<vector<int>>& marks, vector<int>& coins, int num, int target) {

    //cout<<num<<" "<<target<<endl;

    int rel = -1;

    if(target < 0)
      return -1;

    if(marks[num][target] != -2)
      return marks[num][target];

    int one = recursive(marks, coins, num, target - coins[num-1]);
    if(-1 != one)
      one = 1 + one;

    int two = recursive(marks, coins, num-1, target);

    if(-1 != one && -1 != two)
      rel = min(one, two);
    else if(-1 != one)
      rel = one;
    else if(-1 != two)
      rel = two;

    marks[num][target] = rel;

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
