
#include "../utils/list.h"
#include <iostream>

using namespace std;


ListNode* reverseList(ListNode* root) {

  ListNode* prev = NULL;
  ListNode* p = root;

  while (p) {
    ListNode* next = p->next;
    p->next = prev;

    prev = p;
    p = next;
  }

  root = prev;

  return root;
}


int main() {

  vector<int> vals = {1, 2, 4, 5};

  ListNode* root = buildList(vals);
  printList(root);

  root = reverseList(root);
  printList(root);

  return 0;
}
