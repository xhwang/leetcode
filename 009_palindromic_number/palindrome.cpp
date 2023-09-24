#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    if (x == 0) {
      return true;
    }

    int t = x;
    vector<int> value;
    while (t != 0) {
      int m = t % 10;
      t = t / 10;
      value.push_back(m);
    }

    int len = value.size();
    for (int i = 0; i < len / 2; ++i) {
      if (value[i] != value[len - 1 - i]) {
        return false;
      }
    }
    return true;
  }
};


int main() {
  Solution demo = Solution();
  int x;

  x = 121;
  cout << x << ": "<< demo.isPalindrome(x) << endl;

  x = 123;
  cout << x << ": "<< demo.isPalindrome(x) << endl;

  return 0;
}
