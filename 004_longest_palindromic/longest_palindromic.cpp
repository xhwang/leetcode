#include <iostream>
#include <string>

#include <unordered_map>

#include <set>
#include <deque>

using namespace std;


class Solution {
 public:
  string longestPalindrome(string s) {
    string rel = "";
    for (int i = 0; i < s.size(); ++i) {
      int left = i - 1;
      int right = i + 1;
      while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left;
        ++right;
      }
      string sub = s.substr(left + 1, right - left - 1);
      if (sub.size() > rel.size()) {
        rel = sub;
      }
    }

    for (int i = 0; i < s.size(); ++i) {
      int left = i;
      int right = i + 1;
      while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left;
        ++right;
      }
      string sub = s.substr(left + 1, right - left - 1);
      if (sub.size() > rel.size()) {
        rel = sub;
      }
    }

    return rel;
  }
};

int main() {
  Solution demo = Solution();

  string s;
  string palindrome;

  // s = "c";
  // palindrome = demo.longestPalindrome(s);
  // cout << s << " " << palindrome<<endl;

  // s = "umvejcuuk";
  // palindrome = demo.longestPalindrome(s);
  // cout << s << " " << palindrome<<endl;

  s = "bbbbb";
  palindrome = demo.longestPalindrome(s);
  cout << s << " " << palindrome<<endl;

  s = "pwwkew";
  palindrome = demo.longestPalindrome(s);
  cout << s << " " << palindrome<<endl;

  return 0;
}
