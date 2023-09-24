#include <deque>
#include <iostream>
#include <vector>


using namespace std;

struct Node {
  int val;
  Node *left;
  Node *right;
  Node(): val(0), left(nullptr), right(nullptr) {}
  Node(int v): val(v), left(nullptr), right(nullptr) {}
};


Node* buildTree(const vector<int>& nums) {
  if (nums.size() == 0) {
    return nullptr;
  }
  Node* root = new Node(nums[0]);
  deque<Node *> wide_deq = {root};

  for (int i = 1; i < nums.size(); i += 2) {
    Node* p = wide_deq.front();
    wide_deq.pop_front();
    if (!p) {
      continue;
    }
    if (nums[i] != -1) {
      p->left = new Node(nums[i]);
      cout << "left " << nums[i] << endl;
    } else {
      cout << "left " << "-1" << endl;
    }
    if (nums[i + 1] != -1) {
      p->right = new Node(nums[i + 1]);
      cout << "right " << nums[i+1] << endl;
    } else {
      cout << "right " << "-1" << endl;
    }
    wide_deq.push_back(p->left);
    wide_deq.push_back(p->right);
  }
  return root;
}

void printTree(Node* root) {
  if (!root) {
    cout << "null" << endl;
    return;
  }

  int cur_lvl = 0;
  bool has_next_lvl = false;
  deque<pair<Node*, int>> deq = {make_pair(root, cur_lvl)};

  do {
    auto t = deq.front();
    deq.pop_front();

    int lvl = t.second;
    if (lvl != cur_lvl) {
      cur_lvl = lvl;
      if (!has_next_lvl) {
        break;
      }
      has_next_lvl = false;
    }

    Node *node = t.first;
    if (node) {
      cout << node->val << " ";
      deq.emplace_back(node->left, lvl + 1);
      deq.emplace_back(node->right, lvl + 1);
      if (node->left || node->right) {
        has_next_lvl = true;
      }
    } else {
      cout << "null" << " ";
      deq.emplace_back(nullptr, lvl + 1);
      deq.emplace_back(nullptr, lvl + 1);
    }
  } while (!deq.empty());
}

int main() {
  vector<int> nums = {1, 2, -1, 3, 4};
  Node* root = buildTree(nums);
  printTree(root);

  return 0;
}
