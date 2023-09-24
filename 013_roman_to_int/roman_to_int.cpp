// You are given an integer array height of length n. 
// There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    unordered_map<string, int> roman_num_map;
    roman_num_map["IV"] = 4;
    roman_num_map["IX"] = 9;
    roman_num_map["XL"] = 40;
    roman_num_map["XC"] = 90;
    roman_num_map["CD"] = 400;
    roman_num_map["CM"] = 900;

    roman_num_map["I"] = 1;
    roman_num_map["V"] = 5;
    roman_num_map["X"] = 10;
    roman_num_map["L"] = 50;
    roman_num_map["C"] = 100;
    roman_num_map["D"] = 500;
    roman_num_map["M"] = 1000;

    int value = 0;
    for (int i = 0; i < s.size();) {
      string t = s.substr(i, 2);
      if (roman_num_map.find(t) != roman_num_map.end()) {
        value += roman_num_map[t];
        i += 2;
      } else {
        t = s.substr(i, 1);
        value += roman_num_map[t];
        ++i;
      }
    }

    return value;
  }
};

int main() {
  Solution demo = Solution();
  string s;
  s = "III";
  cout << s << " 3 vs " << demo.romanToInt(s) << endl;

  s = "LVIII";
  cout << s << " 58 vs " << demo.romanToInt(s) << endl;

  s = "MCMXCIV";
  cout << s << " 1994 vs " << demo.romanToInt(s) << endl;

  return 0;
}
