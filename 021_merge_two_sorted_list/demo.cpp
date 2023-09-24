#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
      ListNode dummy = ListNode(0);
      ListNode* pos = &dummy;

      while (l1 && l2) {
        if (l1->val <= l2->val) {
          pos->next = l1;
          l1 = l1->next;
        }
        else {
          pos->next = l2;
          l2 = l2->next;
        }
        pos = pos->next;
      }

      pos->next = l1 != NULL ? l1 : l2;

      return dummy.next;
    }
};


int main() {

  return 0;
}
