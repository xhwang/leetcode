#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct TreeNode {

  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x):val(x), left(NULL), right(NULL) {}

};

class Solution {

public:

  int rob(TreeNode* root) {
    int rel = 0;

    int rob[2] = {0, 0}; 

    recursive(root, rob[0], rob[1]);

    rel = rob[0] > rob[1] ? rob[0] : rob[1];

    return rel;
  }

  void recursive(TreeNode* root, int& rob, int& norob) {

    if(!root) return;

    int left[2] = {0, 0}; 
    int right[2] = {0, 0};

    recursive(root->left, left[0], left[1]);
    recursive(root->right, right[0], right[1]);

    rob = root->val + left[1] + right[1];
    norob = max(left[0], left[1]) + max(right[0], right[1]);
  }

};

TreeNode* addTreeNode(TreeNode* root, string path, TreeNode *node) {

  if(NULL == root)
    return node;

  TreeNode* pt = root;

  char c;
  for(size_t i=0; i<path.size()-1; i++) {
    c = path[i];

    if(c == '1')
      pt = pt->left;
    else
      pt = pt->right;
  }

  c = path[path.size()-1];
  if(c == '1')
    pt->left = node;
  else
    pt->right = node;
  pt = node;

  return root;

}

void printTree(TreeNode* root) {

  TreeNode* pt = root;
  if(pt) {
    cout<<pt->val<<" ";
    if(pt->left)
      printTree(pt->left);
    if(pt->right)
      printTree(pt->right);
  }
}

void destroyTree(TreeNode* root) {

  TreeNode* pt = root;
  if(pt) {

    if(pt->left)
      destroyTree(pt->left);
    if(pt->right)
      destroyTree(pt->right);

    delete(pt);
  
  }

}


int main() {

  Solution demo = Solution();

  int rel;
  TreeNode* root;

  root = NULL;

  root = addTreeNode(root, "", new TreeNode(3));
  root = addTreeNode(root, "1", new TreeNode(2));
  root = addTreeNode(root, "0", new TreeNode(3));
  root = addTreeNode(root, "10", new TreeNode(3));
  root = addTreeNode(root, "00", new TreeNode(1));

  printTree(root);

  rel = demo.rob(root);
  cout<<"rel:"<<rel<<endl;

  destroyTree(root);


  root = NULL;

  root = addTreeNode(root, "", new TreeNode(3));
  root = addTreeNode(root, "1", new TreeNode(4));
  root = addTreeNode(root, "0", new TreeNode(5));
  root = addTreeNode(root, "11", new TreeNode(1));
  root = addTreeNode(root, "10", new TreeNode(3));
  root = addTreeNode(root, "00", new TreeNode(1));

  printTree(root);

  rel = demo.rob(root);
  cout<<"rel:"<<rel<<endl;

  destroyTree(root);


  root = NULL;

  root = addTreeNode(root, "", new TreeNode(4));
  root = addTreeNode(root, "1", new TreeNode(1));
  root = addTreeNode(root, "11", new TreeNode(2));
  root = addTreeNode(root, "111", new TreeNode(3));

  printTree(root);

  rel = demo.rob(root);
  cout<<"rel:"<<rel<<endl;

  destroyTree(root);

}


