// Binary Tree Right Side View

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
private:
    vector<int> result;
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr)
            return result;
        
        // Using stack to implement DFS
        stack<pair<TreeNode*, int>> s;
        // Mark current travel level
        int level = 1;
        
        // Use std::pair to track level of each node
        s.push(make_pair(root, 1));
        while (!s.empty()) {
            // Pop first
            pair<TreeNode*, int> node = s.top();
            TreeNode* tmp = node.first;
            s.pop();
            // Only store rightmost one of each level
            if (node.second == level) {
                result.push_back(tmp->val);
                level++;
            }
            if (tmp->left != nullptr)
                s.push(make_pair(tmp->left, node.second+1));
            if (tmp->right != nullptr)
                s.push(make_pair(tmp->right,node.second+1));
        }
        return result;
    }
};
