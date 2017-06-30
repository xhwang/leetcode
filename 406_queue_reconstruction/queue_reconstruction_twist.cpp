
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

public:

  struct Comp {

    bool operator()(pair<int, int>& one, pair<int, int>& two) {

      if(one.second > two.second)
        return true;
      else if(one.second < two.second)
        return false;
      else if(one.first > two.first)
        return true;
      else
        return false;
    }

  };

  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {

    vector<pair<int, int>> rel;

    make_heap(people.begin(), people.end(), Comp());

    int n = people.size();

    for(int i=0; i < n; i++) {

      pop_heap(people.begin(), people.end(), Comp());

      pair<int, int> v = people.back();
      people.pop_back();

      int m = v.second;

      int j = 0;
      int k = rel.size();
      while(m>0 && j<k) {
        if(rel[j].first >= v.first)
          m--;
        j++;
      }
      while(j<k && rel[j].first < v.first)
        j++;

      vector<pair<int, int>>::iterator it = rel.begin();
      rel.insert(it+j, v);

    }

    printPairVector(rel);


    return rel;
  }

  void printPairVector(vector<pair<int, int>>& vec) {

    for(pair<int, int> v: vec)
      cout<<"["<<v.first<<","<<v.second<<"] ";
    cout<<endl;

  }


};




int main() {

  Solution demo = Solution();

  vector<pair<int, int>> people = {
    {7,0}, {4,4}, {7,1}, {5,0}, {6, 1}, {5, 2}
  };

  demo.reconstructQueue(people);

  return 0;
}


