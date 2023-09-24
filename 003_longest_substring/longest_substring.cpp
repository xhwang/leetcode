#include <iostream>
#include <string>

#include <unordered_map>

#include <set>
#include <deque>

using namespace std;


class Solution {
 public:
  int old_lengthOfLongestSubstring(string s) {
    int length = 0;
    unordered_map<char, int> chars;
    int start = 0;
    for(int i = 0; i < s.size(); ++i) {
      char c = s[i];
      const auto &found = chars.find(c);

      // if found, remove all before including it
      if(found != chars.end()) {
        length = std::max((int)chars.size(), length);

        // another method: not remove but record a index
        // refer to leetcode
        for(int j = start; j <= found->second; j++) {
          chars.erase(s.at(j));
        }

        start = found->second + 1;
      }

      // add new char
      chars[c] = i;
    }

    length = std::max((int)chars.size(), length);

    return length;
  }

  int lengthOfLongestSubstring(string s) {
    if (s.size() == 0) {
      return 0;
    }

    int rel = 1;
    set<char> current_set = {s[0]};
    deque<char> current_deq = {s[0]};

    for (int i = 1; i < s.size(); ++i) {
      if (current_set.find(s[i]) != current_set.end()) {
        if (current_deq.size() > rel) {
          rel = current_deq.size();
        }
        do {
          const auto c = current_deq.front();
          current_set.erase(c);
          current_deq.pop_front();
          if (c == s[i]) {
            break;
          }
        } while(true);
      }
      current_set.insert(s[i]);
      current_deq.push_back(s[i]);
    }

    if (current_deq.size() > rel) {
      rel = current_deq.size();
    }

    return rel;
  }
};

int main() {
  Solution demo = Solution();

  string s;
  int length;

  s = "c";
  length = demo.lengthOfLongestSubstring(s);
  cout<<length<<endl;

  s = "umvejcuuk";
  length = demo.lengthOfLongestSubstring(s);
  cout<<length<<endl;

  s = "bbbbb";
  length = demo.lengthOfLongestSubstring(s);
  cout<<length<<endl;

  s = "pwwkew";
  length = demo.lengthOfLongestSubstring(s);
  cout<<length<<endl;

  return 0;
}
