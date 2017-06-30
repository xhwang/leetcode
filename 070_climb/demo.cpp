#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int climbStairs(int n) {

      if (n == 1)
        return 1;

      int first = 1;
      int second = 2;

      for(int i=3; i<=n; i++) {
        int old_second = second;
        second = first + second;
        first = old_second;
      }

      return second;

    }


};


int main() {

  Solution demo = Solution();
  cout<<demo.climbStairs(1)<<endl;
  cout<<demo.climbStairs(2)<<endl;
  cout<<demo.climbStairs(3)<<endl;
  cout<<demo.climbStairs(4)<<endl;
  cout<<demo.climbStairs(5)<<endl;

  return 0;
}
