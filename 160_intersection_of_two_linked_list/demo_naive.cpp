#include "../utils/list.h"
#include <iostream>

using namespace std;

class Solution {

public:

  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

    int lA = getLength(headA);
    int lB = getLength(headB);

    ListNode* posA = headA;
    ListNode* posB = headB;

    if (lA > lB) {
      int diff = lA - lB;
      while(diff-- > 0) {
        posA = posA->next;
      }
    }

    if (lB > lA) {
      int diff = lB - lA;
      while(diff-- > 0) {
        posB = posB->next;
      }
    }
  
    while(posA && posB) {
    
      if (posA == posB)
        return posA;

      posA = posA->next;
      posB = posB->next;
    }

    return NULL;
  }


  int getLength(ListNode* head) {

    int rel = 0;

    while(head) {
      rel++;
      head = head->next;
    }

    return rel;
  }

};


int main() {

  Solution demo = Solution();

  ListNode* first = buildList(vector<int>()={1});
  ListNode* second = buildList(vector<int>()={5, 6});
  ListNode* third = buildList(vector<int>()={7, 8, 9});

  first->next = third;
  second->next->next = third;

  ListNode* rel = demo.getIntersectionNode(first, second);
  cout<<rel->val<<endl;

}


