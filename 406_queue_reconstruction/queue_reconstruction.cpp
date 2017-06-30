
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

public:

  struct Comp {

    bool operator()(pair<int, int> one, pair<int, int> two) {

      return one.first != two.first ? one.first < two.first : one.second > two.second;

      //if(one.first < two.first)
      //  return true;
      //else if(one.first > two.first)
      //  return false;
      //else if(one.second > two.second)
      //  return true;
      //else
      //  return false;
    }

  };

  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {

    vector<pair<int, int>> rel;

    // using sort
    sort(people.rbegin(), people.rend(), Comp());

    for(size_t i=0; i < people.size(); i++) {

      // insight: insert position just as element second value
      rel.insert(rel.begin()+people[i].second, people[i]);
    }

    return rel;
  }


};

void printPairVector(vector<pair<int, int>>& vec) {

  for(pair<int, int> v: vec)
    cout<<"["<<v.first<<","<<v.second<<"] ";
  cout<<endl;

}


int main() {

  Solution demo = Solution();

  vector<pair<int, int>> people = {
    {7,0}, {4,4}, {7,1}, {5,0}, {6, 1}, {5, 2}
  };

  vector<pair<int, int>> rel = demo.reconstructQueue(people);

  printPairVector(rel);

  return 0;
}


