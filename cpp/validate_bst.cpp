// Validate Binary Search Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // Consider case: [10,5,15,null,null,6,20]
 // 6 is less than 10, however, 6 is in the right tree of 10.
 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        // Check left subtree's max value.
        if (root->left != nullptr && maxBST(root->left) >= root->val) {
            return false;
        }else {
            // Check left subtree
            if (!isValidBST(root->left)) {
                return false;
            }
        }
        // Check right subtree's min value.
        if (root->right != nullptr && minBST(root->right) <= root->val) {
            return false;
        }else {
            // Check right subtree
            if (!isValidBST(root->right)) {
                return false;
            }
        }
        // At last
        return true;
    }
    // Find max value
    int maxBST(TreeNode* root) {
        if (root->right == nullptr) {
            return root->val;
        }
        return maxBST(root->right);
    }
    // Find min value
    int minBST(TreeNode* root) {
        if (root->left == nullptr) {
            return root->val;
        }
        return minBST(root->left);
    }
};

/*
 * Method 2 In order
 * In order transversal of a BST must in increasing order. 
 * So, the stack traceback is in decreasing order.
 * If it is not in order, return false.
 */
class Solution2 {
private:
    stack<TreeNode*> trace;
    void inOrderTrace(TreeNode* root) {
        if (root == nullptr)
            return;
        inOrderTrace(root->left);
        this->trace.push(root);
        inOrderTrace(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        inOrderTrace(root);
        TreeNode * curr = trace.top();
        trace.pop();
        while (!trace.empty()) {
            if (curr->val <= (trace.top())->val)
                return false;
            curr = trace.top();
            trace.pop();
        }
        return true;
    }
};
