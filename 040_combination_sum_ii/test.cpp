#include <iostream>
#include <vector>

using namespace std;


int main() {

  vector<int> rel;

  rel.push_back(1);
  rel.push_back(2);

  cout<<rel.size()<<endl;

  rel.pop_back();


  cout<<rel.size()<<endl;



}
