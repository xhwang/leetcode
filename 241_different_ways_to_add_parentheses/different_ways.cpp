#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {

public:

  vector<int> diffWaysToCompute(string input) {

    vector<int> rel;

    rel = recursive(input, 0, input.size()-1);

    return rel;

  }


  vector<int> recursive(string input, int begin, int end) {

    cout<<"begin "<<begin<<" end "<<end<<endl;
  
    vector<int> rel;

    int i;

    int temp = 0;
    for(i=begin; i<=end; i++) {
      if(input[i]!='+' && input[i]!='-' && input[i]!='*')
        temp = temp*10 + input[i] - '0';
      else
        break;
    }

    if(i>end) {
      rel.push_back(temp);
      return rel;
    }

    for(i = begin; i<end; i++) {

      while(input[i]!='+' && input[i]!='-' && input[i]!='*' && i<end)
        i++;
      if(i >= end)
        break;

      vector<int> left = recursive(input, begin, i-1);
      vector<int> right = recursive(input, i+1, end);

      char op = input[i];

      vector<int> temp = operation(op, left, right);

      rel.insert(rel.end(), temp.begin(), temp.end());

    }

    return rel;
  }


  vector<int> operation(char op, vector<int> left, vector<int> right) {

    vector<int> rel;
    for(int l: left) {

      for(int r: right) {

        int temp = 0;
        switch(op) {
          case '+': temp = l + r; break;
          case '-': temp = l - r; break;
          case '*': temp = l * r; break;
        }
        rel.push_back(temp);
      }
    
    }

    return rel;
  }

};


void print1DVector(vector<int> nums) {
  for(int n: nums)
    cout<<n<<" ";
  cout<<endl;
}

int main() {


  Solution demo = Solution();

  vector<int> rel;
  string input;

  input = "2*3-4*5";
  rel = demo.diffWaysToCompute(input);
  print1DVector(rel);

  input = "12-21-1";
  rel = demo.diffWaysToCompute(input);
  print1DVector(rel);
}


