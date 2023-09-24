#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int> rel(digits.size(), 0);
        
        int c = 1;
        
        for (int i = digits.size()-1; i>=0; i--) {
            
            rel[i] = digits[i] + c;
            
            if (rel[i] == 10) {
                rel[i] = 0;
                c = 1;
            }
            else {
                c = 0;
            }
        }
        
        if (c == 1)
            rel.insert(rel.begin(), 1);
        
        return rel;
        
    }
};
