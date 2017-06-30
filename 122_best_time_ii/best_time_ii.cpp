#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        
        if(prices.size() < 2)
            return 0;
        
        int i = 0;
        int j;
        while(1) {
            
            while(i < prices.size() - 1 && prices[i+1] < prices[i])
                i++;
            j = i+1;
            while(j < prices.size() - 1 && prices[j+1] > prices[j])
                j++;
            
            if(j < prices.size()) {
                profit += prices[j] - prices[i];
                i = j+1;
            }
            else {
                break;
            }
            
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


