
#include <iostream>

using namespace std;

class Solution {

  public:

    string multiply(string num1, string num2) {
        
    }
    
    
    string multiplyChar(string num, char m) {
        
        string rel = "";
        int c = 0;
        
        for (int i=num.size()-1; i>=0; i--) {
            
            int t = (m - '0') * (num[i] - '0') + c;
            
            char s = t % 10 + '0';
            c = t / 10;
            
            rel = s + rel;
        }
        
        if (c != 0)
            rel = (c + '0') + rel;
        
        return rel;
    }
    
    string add(string num1, string num2) {
     
        if (num1.size() < num2.size())
            return add(num2, num1);
        
        string rel = "";
        int c = 0;
        
        for (int i=num1.size()-1; i>=0; i--) {
            
            int j = num2.size() - 1 - (num1.size() - i);
            
            int t = 0;
            if (j >= 0)
                t = (num2[j] - '0') + (num[i] - '0') + c;
            else
                t = (num[i] - '0') + c;
            
            char s = t % 10 + '0';
            c = t / 10;
            
            rel = s + rel;
        }
        
        if (c != 0)
            rel = (c + '0') + rel;
        
        return rel;
        
    }

};


int main() {

  Solution demo = Solution();

}
