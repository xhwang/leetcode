#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int hammingWeight(unsigned int n) {

      int rel = 0;

      while (n) {
        rel++;
        n = n & (n-1);
      }
      return rel;
    }


};


int main() {

  Solution demo = Solution();
  cout<<demo.hammingWeight(1)<<endl;
  cout<<demo.hammingWeight(2)<<endl;
  cout<<demo.hammingWeight(3)<<endl;
  cout<<demo.hammingWeight(4)<<endl;
  cout<<demo.hammingWeight(5)<<endl;

  return 0;
}
