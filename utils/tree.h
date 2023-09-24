
#ifndef _TREE_H_
#define _TREE_H_

#include <queue>
#include <stack>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int v):val(v),left(NULL),right(NULL) {}
};


void printTree(TreeNode* root) {

  if (root == NULL)
    return;

  deque<TreeNode*> q = deque<TreeNode*>();
  q.push_back(root);
  int num = 1;

  while(num > 0) {
    TreeNode* p = q.front();
    q.pop_front();

    if (p == NULL) {
      cout<<"null ";
      q.push_back(NULL);
      q.push_back(NULL);
    }
    else {
      cout<<p->val<<" ";
      num--;

      q.push_back(p->left);
      q.push_back(p->right);

      if(p->left)
        num++;
      if(p->right)
        num++;
    }

  }

  cout<<endl;
}


void travelPreOrderWithStack(TreeNode* root) {

  TreeNode* p = root;
  stack<TreeNode*> s = stack<TreeNode*>();

  while(!s.empty() || p) {
  
    if(p) {
      cout<<p->val<<" ";
      s.push(p);
      p = p->left;
    }
    else {
      p = s.top();
      s.pop();
      p = p->right;
    }

  }

  cout<<endl;
}


void travelInOrderWithStack(TreeNode* root) {

  TreeNode* p = root;
  stack<TreeNode*> s = stack<TreeNode*>();

  while(!s.empty() || p) {
  
    if(p) {
      s.push(p);
      p = p->left;
    }
    else {
      p = s.top();
      s.pop();
      cout<<p->val<<" ";
      p = p->right;
    }

  }

  cout<<endl;
}


#endif
