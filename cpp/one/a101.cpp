/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2 == nullptr;
        if (root2 == nullptr) return false;
        if (root1->val != root2->val) return false;
        
        return isSymmetric(root1->left, root2->right) && 
               isSymmetric(root1->right, root2->left);
    }
};