
#include <iostream>

using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {

  public:

    void connect(TreeLinkNode *root) {
    
      TreeLinkNode* cur = root ;
      TreeLinkNode* head = NULL;
      TreeLinkNode* prev = NULL;

      while (cur) {

        while (cur) {

          if (cur->left) {
            if (prev) {
              prev->next = cur->left;
            }
            else {
              head = cur->left;
            }
            prev = cur->left;
          }

          if (cur->right) {
          
            if (prev) {
              prev->next = cur->right;
            }
            else {
              head = cur->right;
            }
            prev = cur->right;
          }

          cur = cur->next;

        }

        cur = head;
        head = NULL;
        prev = NULL;
      }

    }
};


int main() {

  Solution demo = Solution();

}
