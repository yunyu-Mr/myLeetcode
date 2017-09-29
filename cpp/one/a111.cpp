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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int minLeft = minDepth(root->left),
            minRight = minDepth(root->right);
        
        if      (minLeft == 0)  return 1 + minRight;  // left null
        else if (minRight == 0) return 1 + minLeft;   // right null
        
        return 1 + min (minLeft, minRight);
    }
};