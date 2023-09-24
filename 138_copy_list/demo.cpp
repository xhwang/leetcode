#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 */

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


class SolutionHashMap {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

      RandomListNode* dummy = new RandomListNode(0);

      unordered_map<RandomListNode*, RandomListNode*> map;

      RandomListNode* lpos = dummy;
      RandomListNode* rpos = head;

      while(rpos) {
        RandomListNode* temp = new RandomListNode(rpos->label);
        lpos->next = temp;

        map[rpos] = temp;

        lpos = lpos->next;
        rpos = rpos->next;
      }

      lpos = dummy->next;
      rpos = head;

      while(rpos) {

        if(rpos->random) {
          lpos->random = map[rpos->random];
        }

        lpos = lpos->next;
        rpos = rpos->next;
      }

      return dummy->next;
    }
};


class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

      if (not head)
        return NULL;

      RandomListNode* pos = head;

      while(pos) {
        RandomListNode* temp = new RandomListNode(pos->label);

        temp->next = pos->next;
        pos->next = temp;

        pos = pos->next->next;
      }

      pos = head;

      while(pos) {
        if(pos->random) {
          pos->next->random = pos->random->next;
        }
        pos = pos->next->next;
      }

      RandomListNode* rel = head->next;

      RandomListNode* rpos = rel;
      pos = head;

      while(rpos->next) {

        pos->next = pos->next->next;
        rpos->next = rpos->next->next;

        pos = pos->next;
        rpos = rpos->next;
      }

      pos->next = NULL;

      return rel;

    }

};



int main() {


  Solution demo = Solution();

  RandomListNode one = RandomListNode(1);
  RandomListNode two = RandomListNode(2);
  RandomListNode three = RandomListNode(3);
  RandomListNode four = RandomListNode(4);
  RandomListNode five = RandomListNode(5);

  one.next = &two;
  two.next = &three;
  three.next = &four;
  four.next = &five;

  one.random = &three;
  two.random = &five;
  four.random = &two;

  RandomListNode* rel;
  rel = demo.copyRandomList(&one);

  cout<<rel->next->random->label<<endl;

}

