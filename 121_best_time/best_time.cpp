#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {

public:

  int maxProfit(vector<int>& prices) {

    int profit = 0;

    if(prices.size() == 0)
      return profit;

    vector<int> minPrice(prices.size(), 0);

    minPrice[0] = prices[0];
    for(size_t i=1; i<prices.size(); i++) {

      if(prices[i] < minPrice[i-1])
        minPrice[i] = prices[i];
      else
        minPrice[i] = minPrice[i-1];

      int temp = prices[i] - minPrice[i-1];
      if(temp > profit)
        profit = temp;

    }

    return profit;
  }


};


int main() {


  Solution demo = Solution();

  vector<int> nums;

  int rel;

  nums.clear();
  nums.push_back(7);
  nums.push_back(1);
  nums.push_back(5);
  nums.push_back(3);
  nums.push_back(6);
  nums.push_back(4);

  rel = demo.maxProfit(nums);
  cout<<"rel:"<<rel<<endl;

  nums.clear();
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(5);

  rel = demo.maxProfit(nums);
  cout<<"rel:"<<rel<<endl;
}


