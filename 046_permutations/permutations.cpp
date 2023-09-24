#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rel;
        vector<int> current;
        recursive(rel, nums, current, 0);
        return rel;
    }

    void recursive(vector<vector<int>>& rel,
                   const vector<int>& nums,
                   vector<int>& current,
                   int index) {
        if (index == nums.size()) {
            rel.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (find(current.begin(), current.end(), nums[i]) != current.end()) {
                continue;
            }
            current.push_back(nums[i]);
            recursive(rel, nums, current, index+1);
            current.pop_back();
        }
    }
};

int main() {
  Solution demo = Solution();

  vector<int> s = {1, 2, 3};
  vector<vector<int>> rel = demo.permute(s);
  cout << "6 vs " << rel.size() << endl;

  return 0;
}
