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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        
        int dl = depthBalanced(root->left),
            dr = depthBalanced(root->right);
        
        if (dl < 0 || dr < 0) return false;
        return abs(dl - dr) <= 1;
    }
    
    int depthBalanced(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int dl = depthBalanced(root->left),
            dr = depthBalanced(root->right);
        
        if (dl < 0 || dr < 0) return -1;  // return -1 if it is unbalanced
        if (abs(dl - dr) > 1) return -1;
        
        return 1 + max(dl, dr);  // return depth of current tree.
    }
};