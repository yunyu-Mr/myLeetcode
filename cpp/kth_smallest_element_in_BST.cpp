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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        while (root != nullptr) {
            s.push(root);
            root = root->left;
        }
        
        int count = 0;
        while (!s.empty()) {
            root = s.top();
            s.pop();
            count ++;
            // Check whether count k values.
            if (k == count) 
                return root->val;
            // If not reach k, find more small values.
            if (root->right != nullptr) {
                root = root->right;
                while (root != nullptr) {
                    s.push(root);
                    root = root->left;
                }
            }
        }
        return 0;
    }
};