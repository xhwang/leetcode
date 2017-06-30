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

    rel = recursive(root);

    return rel;
  }

  int recursive(TreeNode* root) {

    int part1 = 0;
    int part2 = 0;

    if(!root) return 0;
    part1 = root->val;

    if(root->left) {
      part2 += recursive(root->left);

      part1 += recursive(root->left->left);
      part1 += recursive(root->left->right);
    }
    if(root->right) {
      part2 += recursive(root->right);

      part1 += recursive(root->right->left);
      part1 += recursive(root->right->right);
    }

    return part1 > part2 ? part1 : part2;

  }

};


TreeNode* buildTree(TreeNode* root, vector<int> values) {

  return NULL;
}


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

  root = addTreeNode(root, "", new TreeNode(4));
  root = addTreeNode(root, "1", new TreeNode(1));
  root = addTreeNode(root, "11", new TreeNode(2));
  root = addTreeNode(root, "111", new TreeNode(3));

  printTree(root);

  rel = demo.rob(root);
  cout<<"rel:"<<rel<<endl;

  destroyTree(root);


}


