#include <vector>
#include <iostream>

using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(): val(0), next(nullptr) {}
  ListNode(int v): val(v), next(nullptr) {}
};


void addListNode(ListNode* head, ListNode* n) {
  ListNode* p = head;
  while(p->next != nullptr) {
    p = p->next;
  }
  p->next = n;
}

void addListNode(ListNode* head, int num) {
  ListNode* p = head;
  while(p->next != nullptr) {
    p = p->next;
  }
  p->next = new ListNode(num);
}


ListNode* buildTree(const vector<int>& nums) {
  ListNode* head = new ListNode();
  for (const int n : nums) {
    addListNode(head, n); 
  }
  return head->next;
}

void printList(ListNode* head) {
  ListNode* p = head;
  while(p->next != nullptr) {
    cout << p->val << "->";
    p = p->next;
  }
  cout<<p->val<<endl;
}


int main() {
  ListNode* l1 = new ListNode(9);
  addListNode(l1, new ListNode(9));
  addListNode(l1, new ListNode(9));
  printList(l1);

  ListNode* l2 = new ListNode(2);
  addListNode(l2, new ListNode(2));
  printList(l2);

  return 0;
}
