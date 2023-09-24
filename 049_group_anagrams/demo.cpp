
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

  public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

      vector<vector<string>> rel;

      unordered_map<string, int> posMap;

      for (auto s:strs) {

        vector<int> counts(26, 0);
        for (char c: s) {
          counts[c-'a']++;
        }

        string orderStr;
        for (size_t i=0; i<counts.size(); i++) {
          if (counts[i] != 0) {
            for (int j=0; j<counts[i]; j++) {
              orderStr += 'a' + i;
            }
          }
        }

        unordered_map<string, int>::const_iterator it = posMap.find(orderStr);

        if (it != posMap.end()) {
          rel[it->second].push_back(s);
        }

        else {

          vector<string> row = {s};
          rel.push_back(row);

          posMap[orderStr] = rel.size() - 1;

          // TODO: make pair error
          // posMap.insert(make_pair<string, int>(orderStr, rel.size()-1));
        }
      }

      return rel;
    }
};
          
int main() {

  Solution demo = Solution();

  vector<string> strs = {"tte", "eat", "tea"};

  vector<vector<string>> rel = demo.groupAnagrams(strs);

  for (auto v: rel) {
    for (auto str: v) {
      cout<<str<<" ";
    }
    cout<<endl;
  }

}
