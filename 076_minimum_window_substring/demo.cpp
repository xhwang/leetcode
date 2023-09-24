
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {

  public:

    string minWindow(string s, string t) {

      vector<int> map(128,0);

      // map 中只有在 t 出现过的字符个数能 > 0
      for(auto c: t)
        map[c]++;

      int counter = t.size(), begin=0, end=0, d=INT_MAX, head=0;

      while (end < int(s.size())) {

          if(map[s[end++]]-- > 0)
            counter--; //in t

          while(counter==0){ //valid

              if(end-begin<d) {
                head = begin;
                d = end-begin;
              }

              // begin 在 end 之后, 所以 begin 处的字符,
              // 其个数要么为0 (即出现在t中), 要么为负
              // 如果为0, 说明这个出现在t中, 但是已经出了范围
              if(map[s[begin++]]++ == 0)
                counter++;  //make it invalid
          }  
      }

      return d==INT_MAX? "":s.substr(head, d);
    }

};


int main() {

  Solution demo = Solution();

  string s = "ADOBECODEBANC";
  string t = "CABC";

  string rel = demo.minWindow(s, t);

  cout<<rel<<endl;
}


