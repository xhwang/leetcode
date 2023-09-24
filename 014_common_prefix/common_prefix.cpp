#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    string rel = "";
    int index = 0;
    bool flag;
    do {
      flag = true;
      if (index >= strs[0].size()) {
          break;
      }
      char c = strs[0][index];
      for (int i = 1; i < strs.size(); ++i) {
        if (index < strs[i].size() && strs[i][index] == c) {
          continue;
        } else {
          flag = false;
          break;
        }
      }
      if (flag) {
        ++index;
        rel += c;
      }
    } while (flag);
    return rel;
  }
};

int main() {
  Solution demo = Solution();

  vector<string> s = {"MCMXCIV", "MC", "MCB"};
  cout << "MC vs " << demo.longestCommonPrefix(s) << endl;

  return 0;
}
