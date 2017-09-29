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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        
        return isLess(root->val, root->left) &&
               isGreater(root->val, root->right) &&
               isValidBST(root->left) && 
               isValidBST(root->right);
    }
    
    bool isLess(int val, TreeNode* root) {
        if (root == NULL) return true;
        
        while (root->right != NULL)
            root = root->right;
        return val > root->val;
    }
    
    bool isGreater(int val, TreeNode* root) {
        if (root == NULL) return true;
        
        while (root->left != NULL)
            root = root->left;
        return val < root->val;
    }
};