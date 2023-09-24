
#include <iostream>
#include "../utils/list.h"

using namespace std;

class Solution {

  public:

    ListNode* partition(ListNode* head, int x) {
        
        ListNode* first = new ListNode(0);
        ListNode* second = new ListNode(0);
        
        ListNode* pos = head;
        ListNode* firstPos = first;
        ListNode* secondPos = second;
        
        while (pos != NULL) {
            
            if (pos->val < x) {
                firstPos->next = pos;
                firstPos = firstPos->next;
            }
            else {
                secondPos->next = pos;
                secondPos = secondPos->next;
            }
            
            pos = pos->next;

            firstPos->next = NULL;
            secondPos->next = NULL;

            // cout<<"first"<<endl;
            // printList(first);
            // cout<<"second"<<endl;
            // printList(second);
        }
        
        firstPos->next = second->next;
        
        return first->next;
    }

};


int main() {

  Solution demo = Solution();

  vector<int> nums = {1, 4, 3, 2, 5, 2};
  ListNode* head = buildList(nums);
  printList(head);

  ListNode* rel = demo.partition(head, 3);
  printList(rel);

}
