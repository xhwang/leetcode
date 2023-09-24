
#include <iostream>
#include <vector>
#include <deque>
#include "../utils/tree.h"

using namespace std;

class Solution {

  public:

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    
      vector<vector<int>> rel;

      deque<TreeNode*> level;

      if (root)
        level.push_back(root);

      int order = 1;
      while (!level.empty()) {
        int sz = level.size();
        vector<int> v;

        if (order == 1) {
          for (int i=0; i<sz; i++) {
            TreeNode* t = level.front();
            level.pop_front();
            v.push_back(t->val);
            if (t->left)
              level.push_back(t->left);
            if (t->right)
              level.push_back(t->right);
          }
          rel.push_back(v);
          order = 0;
        }
        else {
          for (int i=0; i<sz; i++) {
            TreeNode* t = level.back();
            level.pop_back();
            v.push_back(t->val);
            if (t->right)
              level.push_front(t->right);
            if (t->left)
              level.push_front(t->left);
          }
          rel.push_back(v);
          order = 1;
        }
      }

      return rel;
    }

};


int main() {


  TreeNode* root = new TreeNode(3);

  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  Solution demo = Solution();

  vector<vector<int>> rel = demo.zigzagLevelOrder(root);

  for (auto v: rel) {
    for (auto i: v) {
      cout<<i<<" ";
    }
    cout<<endl;
  }

}
