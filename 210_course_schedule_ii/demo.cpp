
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {

  public:

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {

      vector<int> rel;

      vector<vector<int>> graph(numCourses, vector<int>(0));
      vector<int> in(numCourses, 0);

      for (auto p: prerequisites) {
        graph[p.second].push_back(p.first);
        in[p.first]++;
      }

      queue<int> q;
      for (int i=0; i<numCourses; i++) {
        if (in[i] == 0)
          q.push(i);
      }

      while (!q.empty()) {
      
        int t = q.front();
        q.pop();

        rel.push_back(t);

        for (auto c: graph[t]) {
          in[c]--;
          if (in[c] == 0)
            q.push(c);
        }
      
      }

      // TODO: note fail situation
      for (int i = 0; i < numCourses; ++i) {
        if (in[i] != 0) {
            vector<int> fail;
            return fail;
        }      
      }

      return rel;
    }

};


int main() {

  /*
  Solution demo = Solution();

  int numCourses = 3;
  vector<pair<int, int>> prerequisites;

  prerequisites.push_back(pair<int, int>(0, 1));
  vector<int> rel = demo.findOrder(numCourses, prerequisites);
  */

  
  vector<int> v = {1, 2, 3, 4, 5};
  random_shuffle(v.begin(), v.end());

  for (size_t i=0; i<v.size(); i++) {
    cout<<v[i]<<endl;
  }


}


