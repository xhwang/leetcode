#include "../utils/list.h"
#include <iostream>

using namespace std;

class Solution {

public:

  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

    ListNode* cur1 = headA;
    ListNode* cur2 = headB;

    while (cur1 != cur2) {
      cur1 = cur1 ? cur1->next : headB;
      cur2 = cur2 ? cur2->next : headA;
    }

    return cur1;
  }
};


int main() {

  Solution demo = Solution();

  ListNode* first = buildList(vector<int>()={1});
  ListNode* second = buildList(vector<int>()={5, 6});

  // ListNode* third = buildList(vector<int>()={7, 8, 9});
  // first->next = third;
  // second->next->next = third;

  ListNode* rel = demo.getIntersectionNode(first, second);

  if (rel) 
    cout<<rel->val<<endl;
  else
    cout<<"null"<<endl;
}


