/**
 * Binary Tree Preorder Traversal
 */
 
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr)
            return result;
        // Add root
        result.push_back(root->val);
        // Append left tree
        vector<int> resLeft = preorderTraversal(root->left);
        result.insert(result.end(), resLeft.begin(), resLeft.end());
        // Append right tree
        vector<int> resRight = preorderTraversal(root->right);
        result.insert(result.end(), resRight.begin(), resRight.end());
        //
        return result;
    }
};
