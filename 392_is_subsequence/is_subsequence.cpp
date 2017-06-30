
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {

public:

  bool isSubsequence(string s, string t) {

    bool rel = true;

    size_t j = 0;
    for(size_t i = 0; i < s.length(); i++) {

      char c = s[i];
      size_t pos = t.find(c, j);

      if(pos == string::npos) {
        rel = false;
        break;
      }
      else {
        cout<<c<<" "<<pos<<endl;
        j = pos + 1;
      }
    
    }

    return rel;
  
  }

};


int main() {

  Solution demo = Solution();

  string s;
  string t;

  bool rel;

  s = "abc";
  t = "ahbgdc";
  rel = demo.isSubsequence(s, t);
  cout<<rel<<endl;

  s = "axc";
  t = "ahbgdc";
  rel = demo.isSubsequence(s, t);
  cout<<rel<<endl;
}
