
#include <iostream>

using namespace std;


struct ListNode {

  int val;
  ListNode *next;
  ListNode(int v): val(v), next(NULL) {}

};


class Solution {

  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

      // make sure the start of the following loop is reasonable
      if(l1 == NULL && l2 == NULL)
        return NULL;

      ListNode* rel = new ListNode(0);

      int c = 0;
      int val;
      ListNode* temp = rel;
    
      while(1) {

        // add three component values
        val = c;
        if(l1 != NULL)
          val = l1->val + val;
        if(l2 != NULL)
          val = l2->val + val;

        // update c and val
        if(val >= 10)
          c = 1;
        else
          c = 0;
        val = val % 10;

        temp->val = val;

        // move to next
        if(l1 != NULL)
          l1 =  l1->next;
        if(l2 != NULL)
          l2 =  l2->next;
      
        // check whether create another node
        if(l1 != NULL || l2 != NULL || c == 1) {
          temp->next = new ListNode(0);
          temp = temp->next;
        }
        else
          break;

      }
    
      return rel;
    
    }


    void addListNode(ListNode* l, ListNode* n) {

      ListNode* p = l;
      while(p->next != NULL) {
        p = p->next;
      }

      p->next = n;
    }

    void printList(ListNode* l) {
    
      while(l->next != NULL) {
        cout<<l->val<<"->";
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

}
