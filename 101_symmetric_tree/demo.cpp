/**
 * Definition for a binary tree node.
 */



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {

public:
    bool isSymmetric(TreeNode* root) {
        
        if(root == nullptr)
            return true;
        
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode* left, TreeNode* right) {
        
        if(left == nullptr and right == nullptr)
            return true;
        
        if(left == nullptr || right == nullptr)
            return false;
        
        bool zero = left->val == right->val;
        bool first = helper(left->left, right->right);
        bool second = helper(left->right, right->left);
        
        return zero && first && second;
        
    }
};
