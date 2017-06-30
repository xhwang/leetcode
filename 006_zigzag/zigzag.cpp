#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {

public:
  string convert(string s, int numRows) {

    // numRows 0, wrong input, still return s
    if(numRows <= 1 || s.length() == 0)
      return s;

    string t = "";
    vector<string> lines(numRows, "");

    int r = 0; 
    int direction = 1;
    for(size_t i=0; i<s.length(); i++) {
      lines[r].push_back(s[i]);

      r = r + direction;

      if(r == numRows - 1) {
        direction = -1;
      }
      if(r == 0) {
        direction = 1;
      }
    }

    for(size_t i=0; i<lines.size(); i++) {
      cout<<lines[i]<<endl;
      t.append(lines[i]);
    }

    return t;

  }


};


int main() {


  Solution demo = Solution();

  string s;
  int numRows;

  string rel;

  s  = "PAYPALISHIRING";
  numRows = 3;
  rel = demo.convert(s, numRows);
  cout<<"input :"<<s<<endl;
  cout<<"output:"<<rel<<endl;

  s  = "";
  numRows = 2;
  rel = demo.convert(s, numRows);
  cout<<"input :"<<s<<endl;
  cout<<"output:"<<rel<<endl;
}


