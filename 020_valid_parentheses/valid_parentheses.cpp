
#include <iostream>
#include <string>
#include <stack>

using namespace std;


class Solution {


public:
  bool isValid(string s) {

    bool rel = true;
    stack<char> chars;
    
    for(unsigned int i = 0; i<s.size(); i++) {
      
      char c = s.at(i);

      if(c == '(' || c == '{' || c == '[') {
        chars.push(c);
      }
      else {

        if(chars.empty()) {
          rel = false;
          break;
        }

        char lc = chars.top();
        chars.pop();

        if(!isMatched(lc, c)) {
          rel = false;
          break;
        }
        
      }

    }

    // important
    if(!chars.empty())
      rel = false;

    return rel;
  }

  bool isMatched(char l, char r) {

    bool rel;

    switch(l) {
      case '(': rel=r==')'?true:false; break;
      case '[': rel=r==']'?true:false; break;
      case '{': rel=r=='}'?true:false; break;
      default: rel = false;
    }
    return rel;
  }


};


int main() {

  Solution demo = Solution();

  string s = "(({}))";
  bool rel = demo.isValid(s);
  cout<<rel<<endl;

}
