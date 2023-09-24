
#ifndef _LIST_H_
#define _LIST_H_

#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int v):val(v),next(NULL) {}
};


ListNode* addNode(ListNode* root, ListNode* node) {

  if (root == NULL)
    return node;
  else {
    ListNode* p = root;
    while(p->next != NULL)
      p = p->next;
    p->next = node;
  }

  return root;
}

ListNode* buildList(vector<int>& arr) {

  ListNode* dummpy = new ListNode(0);

  for(size_t i=0; i<arr.size(); i++) {
    dummpy = addNode(dummpy, new ListNode(arr[i]));
  }

  ListNode* root = dummpy->next;
  delete dummpy;

  return root;
}


void printList(ListNode* root) {
  ListNode* p = root;
  while(p != NULL) {
    cout<<p->val<<" ";
    p = p->next;
  }
  cout<<endl;
}

#endif
