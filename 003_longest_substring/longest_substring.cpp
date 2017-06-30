
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {

public:

  int lengthOfLongestSubstring(string s) {

    int length = 0;

    unordered_map<char, int> chars;
    int start = 0;

    for(unsigned int i = 0; i<s.size(); i++) {
    
      char c = s.at(i);
      auto found = chars.find(c);

      // if found, remove all before including it
      if(found != chars.end()) {

        length = std::max((int)chars.size(), length);

        // another mothod: not remove but record a index
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


}
