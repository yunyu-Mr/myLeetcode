/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// A case is useful to understand:
//    3
//  4
//    2
//      1
// result should be : [1,2,4,3]

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr)
            return result;
        
        stack<TreeNode*> s;  // trasversal stack
        stack<TreeNode*> sp; // post node stack
        
        // Initial: push all of the left node into stack.
        while (root != nullptr) {
            s.push(root);
            root = root->left;
        }
        
        // Iterate until stack empty.
        while (!s.empty()) 
        {
            // If the pop node has right child, it should be track in stack sp.
            // Otherwise, visit it.
            TreeNode* node = s.top();
            if (node->right != nullptr) {
                sp.push(node);
            }else {
                result.push_back(node->val);
            }
            
            // If the current node is the right child of previously track post node,
            // Visit the post node.
            // If not, skip.
            TreeNode* postChild = node;
            while (!sp.empty()) 
            {
                TreeNode* postNode = sp.top();
                if (postChild == postNode->right) {
                    result.push_back(postNode->val);
                    sp.pop();
                    postChild = postNode;
                }
                else 
                    break;
            }
            
            s.pop();
            
            // If right subtree is not empty, push all of it's left nodes into stack
            node = node->right;
            while (node != nullptr) {
                s.push(node);
                node = node->left;
            }
        }
        
        return result;
    }
};