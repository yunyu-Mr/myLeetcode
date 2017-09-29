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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n == 0) return nullptr;
        
        TreeNode *root = new TreeNode(preorder[0]);
        if (n == 1) return root;
        
        for (int i = 0; i < n; i++)
            if (root->val == inorder[i]) {      // Find the root in inorder vector.
                vector<int> preleft(&preorder[1], &preorder[i+1]);  // 1 ~ i
                vector<int> inleft(&inorder[0], &inorder[i]);       // 0 ~ i-1
                root->left = buildTree(preleft, inleft);            // construct left tree
                
                vector<int> preright(&preorder[i+1], &preorder[n]); // i+1 ~ n
                vector<int> inright(&inorder[i+1], &inorder[n]);    // i+1 ~ n
                root->right = buildTree(preright, inright);         // construct right tree
                break;
            }
        return root;
    }
};