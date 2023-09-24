
#include <iostream>
#include "../utils/tree.h"

using namespace std;

class Solution {

  public:

    string serialize(TreeNode* root) {



    }

    int countTreeNodeNumber(TreeNode* root) {
      if (root == NULL)
        return 0;

      int left = countTreeNodeNumber(root->left);
      int right = countTreeNodeNumber(root->right);

      return 1 + left + right;
    }






};


int main() {

  Solution demo = Solution();

}
