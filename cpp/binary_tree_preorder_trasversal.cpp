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
 
 // Solution 1: Recursive (easy)
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

// Solution 2: Non Recursive (medium)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr)
            return result;
        
        stack<TreeNode*> s;
        // Initial: push all of the left node into stack.
        while (root != nullptr) {
            result.push_back(root->val); // add to result
            s.push(root);
            root = root->left;
        }
        // Iterate until stack empty.
        while (!s.empty()) {
            TreeNode* node = s.top();
            node = node->right;
            s.pop();
            // If right subtree is not empty, push all of it's left nodes into stack
            while (node != nullptr) {
                result.push_back(node->val);
                s.push(node);
                node = node->left;
            }
        }
        
        return result;
    }
};


/*
 * Solution 3: Non-recursive method, using stack. Better than method 2.
 */
class Solution 
{
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr)
            return result;

        stack<TreeNode *> s;

        // Push the root node
        s.push(root);

        // Iterate until stack empty
        while (!s.empty()) {
            TreeNode *root = s.top(); s.pop();

            result.push_back(root->val);

            // Attention! Push right first, because stack will pop it later.
            if (root->right != nullptr)
                s.push(root->right);
            // Then push left.
            if (root->left != nullptr)
                s.push(root->left);
        }
        return result;
    }
};