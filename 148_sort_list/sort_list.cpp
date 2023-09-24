#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    ListNode* sortListN2(ListNode* head) {
      if (!head || !head->next) {
        return head;
      }
      ListNode* dummy = new ListNode();
      dummy->next = head;
      ListNode* sort = dummy;
      ListNode* pre = dummy;
      ListNode* cur = dummy->next;
      while (cur) {
        int min_value = cur->val;
        ListNode* min_pre = pre;
        ListNode* min_cur = cur;    
        while (cur->next) {
          pre = cur;
          cur = cur->next;
          if (cur->val < min_value) {
            min_value = cur->val;
            min_pre = pre;
            min_cur = cur;
          }
        }

        min_pre->next = min_cur->next;
        min_cur->next = sort->next;
        sort->next = min_cur;

        sort = sort->next;
        pre = sort;
        cur = sort->next;  
      }

      return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
      if (!head || !head->next) {
        return head;
      }
      sort(head);
    }

    ListNode* sort(ListNode* head) {
      if (!head->next) {
        return head;
      }
      ListNode* mid = head;
    }

};


int main() {
  Solution demo = Solution();

  return 0;
}
