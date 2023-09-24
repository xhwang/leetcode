
#include <iostream>

using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int v): val(v), next(nullptr) {}
};


class Solution {

  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

      // make sure the start of the following loop is reasonable
      if(l1 == nullptr && l2 == nullptr)
        return nullptr;

      ListNode* rel = new ListNode(0);

      int c = 0;
      int val;
      ListNode* temp = rel;

      while(1) {
        // add three component values
        val = c;
        if (l1) {
          val += l1->val;
        }
        if (l2) {
          val += l2->val;
        }

        // update c and val
        c = val / 10;
        val = val % 10;

        temp->val = val;

        // move to next
        if (l1) {
          l1 = l1->next;
        }
        if (l2) {
          l2 =  l2->next;
        }

        // check whether create another node
        if(l1 != nullptr || l2 != nullptr || c == 1) {
          temp->next = new ListNode(0);
          temp = temp->next;
        } else {
          break;
        }
      }

      return rel;
    }

    void addListNode(ListNode* l, ListNode* n) {
      ListNode* p = l;
      while(p->next != nullptr) {
        p = p->next;
      }

      p->next = n;
    }

    void printList(ListNode* l) {
      while(l->next != nullptr) {
        cout << l->val << "->";
        l = l->next;
      }
      cout<<l->val<<endl;
    }

};


int main() {
  Solution demo = Solution();

  ListNode* l1 = new ListNode(9);
  demo.addListNode(l1, new ListNode(9));
  demo.addListNode(l1, new ListNode(9));
  demo.printList(l1);

  ListNode* l2 = new ListNode(2);
  demo.addListNode(l2, new ListNode(2));
  demo.printList(l2);

  ListNode* rel = demo.addTwoNumbers(l1, l2);
  demo.printList(rel);
  return 0;
}
