
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

  public:

    int nthUglyNumber(int n) {

      // Pos of last number which multiply 2, 3, 5
      int t1 = 0;
      int t2 = 0;
      int t3 = 0;

      vector<int> temp(n);

      temp[0] = 1;

      for (int i=1; i<n; i++) {
      
        int rel = min(min(temp[t1]*2, temp[t2]*3), temp[t3]*5);
        temp[i] = rel;

        if (temp[t1]*2 == rel)
          t1++;

        if (temp[t2]*3 == rel)
          t2++;
      
        if (temp[t3]*5 == rel)
          t3++;

      }

      return temp[n-1];
    }


};


int main() {

  Solution demo = Solution();

  int rel;
  rel = demo.nthUglyNumber(1);
  cout<<rel<<endl;
  rel = demo.nthUglyNumber(2);
  cout<<rel<<endl;
  rel = demo.nthUglyNumber(3);
  cout<<rel<<endl;
  rel = demo.nthUglyNumber(4);
  cout<<rel<<endl;
  rel = demo.nthUglyNumber(5);
  cout<<rel<<endl;
  rel = demo.nthUglyNumber(6);
  cout<<rel<<endl;
}


