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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode *right = root->right,
                 *p = root;
        // Replace right-tree by left-tree
        root->right = root->left;
        root->left = nullptr;
        
        // Append right tree.
        while (p->right)
            p = p->right;
        p->right = right;
    }
};