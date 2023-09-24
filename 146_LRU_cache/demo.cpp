

#include <iostream>
#include <unordered_map>

using namespace std;

struct DListNode {
  int key;
  int val;
  DListNode* prev;
  DListNode* next;

  DListNode(int k, int v):key(k), val(v), prev(NULL), next(NULL) {}
};


class DList {

  public:
    DList():head(NULL), tail(NULL) {}

    DListNode* pop_back() {
      DListNode* rel = tail;
      tail = tail->prev;
      if (tail)
        tail->next = NULL;

      return rel;
    }

    void push_front(DListNode* node) {

      node->prev = NULL;
      node->next = head;
      if (head) {
        head->prev = node;
      }
      head = node;
      if (!tail)
        tail = node;
    }

    void move_front(DListNode* node) {
      if (node == head)
        return;
      if (node == tail) {
        tail = tail->prev;
        tail->next = NULL;
      }

      if (node->prev)
        node->prev->next = node->next;

      if (node->next)
        node->next->prev = node->prev;

      push_front(node);
    }

    void print() {
      DListNode* pos = head;
      while (pos) {
        cout<<pos->val<<" ";
        pos = pos->next;
      }
      cout<<endl;
    }

  private:
    DListNode* head;
    DListNode* tail;
};


class LRUCache {

  public:

    LRUCache(int capacity) {
    
      // 双向链表表示
      l = DList();
      cur = 0;
      cap = capacity;
    
    }

    void put(int key, int value) {
    
      unordered_map<int, DListNode*>::const_iterator got = map.find(key);
      
      if (got != map.end()) {
        DListNode* node = got->second;
        node->val = value;
        l.move_front(node);
      }
      else {
        if (cur == cap) {
          DListNode* tail = l.pop_back();
          map.erase(tail->key);
          delete tail;
          cur--;
        }

        DListNode* node = new DListNode(key, value);
        l.push_front(node);
        cur++;

        map.insert(pair<int, DListNode*>(key, node));
      }
    
      // l.print();

    }

    int get(int key) {
    
      unordered_map<int, DListNode*>::const_iterator got = map.find(key);
      
      if (got != map.end()) {
        DListNode* node = got->second;
        l.move_front(node);
        // l.print();
        return node->val;
      }
      else {
        return -1;
      }

    }

  private:

    int cur;
    int cap;
    DList l;
    unordered_map<int, DListNode*> map;

};


int main() {

  LRUCache cache = LRUCache(2);
  
/*
  cache.put(1, 1);
  cache.put(2, 2);
  cache.get(1);       // returns 1
  cache.put(3, 3);    // evicts key 2
  cache.get(2);       // returns -1 (not found)
  cache.put(4, 4);    // evicts key 1
  cache.get(1);       // returns -1 (not found)
  cache.get(3);       // returns 3
  cache.get(4);       // returns 4
*/

  cache.put(1, 1);
  cache.put(2, 2);
  cout<<cache.get(1)<<endl;       // returns 1
  cache.put(3, 3);                // evicts key 2
  cout<<cache.get(2)<<endl;       // returns -1 (not found)
  cache.put(4, 4);                // evicts key 1
  cout<<cache.get(1)<<endl;       // returns -1 (not found)
  cout<<cache.get(3)<<endl;       // returns 3
  cout<<cache.get(4)<<endl;       // returns 4

}
