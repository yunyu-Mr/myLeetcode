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
    int sumNumbers(TreeNode* root) {        
        return dfs(root, 0);     // DFS
    }
    
    int dfs(TreeNode* root, int pathSum) {
        if (root == NULL) return 0;
        
        pathSum = 10*pathSum + root->val;  // current path sum
        
        if (!root->left && !root->right)
            return pathSum;
        
        return dfs(root->left, pathSum) + 
               dfs(root->right, pathSum);
    }
};