
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {

public:
  int firstUniqChar(string s) {

    // TODO: char is spetial type, can be hashed
    vector<int> map(256, 0);

    for (auto c:s)
      map[c]++;

    for (size_t i = 0; i<s.size(); i++) {
      if (map[s[i]] == 1)
        return i;
    }

    return -1;
  }

};


int main() {

  Solution demo = Solution();

  string s = "loveleetcode";
  int rel = demo.firstUniqChar(s);
  cout<<rel<<endl;
}


