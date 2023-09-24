// Given the root of a binary tree, imagine yourself standing on the right side of it,
// return the values of the nodes you can see ordered from top to bottom.

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> rel;
    if (!root) {
      return rel;
    }

    deque<pair<TreeNode*, int>> deq = {make_pair(root, 0)};

    while (!deq.empty()) {
      auto t = deq.front();
      TreeNode *node = t.first;
      int index = t.second;
      if (index > static_cast<int>(rel.size()) - 1) {
        rel.push_back(node->val);
      } else {
        rel[index] = node->val;
      }
      if (node->left) {
        deq.emplace_back(node->left, index + 1);
      }
      if (node->right) {
        deq.emplace_back(node->right, index + 1);
      }
      deq.pop_front();
    }

    return rel;
  }

};

int main() {
  Solution demo = Solution();

  return 0;
}
