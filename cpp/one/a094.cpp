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
    /*
     * Recursive method
     */
    void inorder(TreeNode* root, vector<int> &traversal) {
        if (root == nullptr) return;
        
        inorder(root->left, traversal);
        traversal.push_back(root->val);
        inorder(root->right, traversal);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> trav;
        // inorder(root, trav);
        
        // Move to left.
        TreeNode *curr = root;
        stack<TreeNode *> s;
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
        // Traversal
        while (!s.empty())
        {
            curr = s.top();
            s.pop();
            
            trav.push_back(curr->val);  // visit
            
            curr = curr->right;         // trace right subtree
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
        }
        
        return trav;
    }
};