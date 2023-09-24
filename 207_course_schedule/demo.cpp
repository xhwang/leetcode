
#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <unordered_set>


using namespace std;

class Solution {

  public:

    bool canFinish(int numCourses, vector<pair<int, int>>& pre) {

      bool rel = true;

      // TODO: initialization () vs {}
      vector<unordered_set<int>> graph(numCourses, unordered_set<int>());
      vector<int> in_degree(numCourses, 0);

      for (auto p: pre) {
        graph[p.second].insert(p.first);
        in_degree[p.first]++;
      }

      deque<int> q;

      for (int i=0; i<numCourses; i++) {
        if (in_degree[i] == 0)
          q.push_back(i);
      }

      while (!q.empty()) {
      
        int p = q.front();
        q.pop_front();

        for (int i: graph[p]) {
          in_degree[i]--;
          if (in_degree[i] == 0)
            q.push_back(i);
        }

      }

      for (size_t i = 0; i < in_degree.size(); i++) {
        if (in_degree[i] != 0)
          return false;
      }

      return rel;
    }


};


int main() {

  Solution demo = Solution();

  int numCourses = 2;

  vector<pair<int, int>> pre;
  pre.push_back(pair<int, int>(1, 0));

  bool rel = demo.canFinish(numCourses, pre);
  cout<<rel<<endl;

  pre.push_back(pair<int, int>(0, 1));

  rel = demo.canFinish(numCourses, pre);
  cout<<rel<<endl;

}


