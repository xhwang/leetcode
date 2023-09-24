
#include <iostream>
#include <vector>

using namespace std;

class Solution {

  public:

    vector<vector<int>> combine(int n, int k) {

      vector<vector<int>> rel;
      vector<int> path;

      bt(rel, path, 1, n, k);
      return rel;
    }

    void bt(vector<vector<int>>& rel, vector<int>& path, size_t begin, size_t n, size_t k) {

      if (path.size() == k) {
        rel.push_back(path);
        return;
      }

      for (size_t i=begin; i<=n; i++) {
        path.push_back(i);
        bt(rel, path, i+1, n, k);
        path.pop_back();
      }

    }

};


int main() {

  Solution demo = Solution();

  vector<vector<int>> rel = demo.combine(4, 2);

  for (auto v: rel) {
    for (auto i: v) 
      cout<<i<<" ";
    cout<<endl;
  }

}
