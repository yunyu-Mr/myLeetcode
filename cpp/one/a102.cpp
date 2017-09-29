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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> tvl;
        if (root == nullptr) return tvl;
        
        queue<pair<TreeNode*, int>> q;  // Queue: Track node and level.
        q.push(make_pair(root, 0));     // init
        
        while (!q.empty()) {
            TreeNode *node = q.front().first;  // get front.
            int level = q.front().second;
            q.pop();
            
            if (level >= tvl.size())
                tvl.push_back(vector<int>());
            tvl[level].push_back(node->val);
            
            // Next level
            if (node->left)
                q.push(make_pair(node->left, level+1));
            if (node->right)
                q.push(make_pair(node->right, level+1));
        }
        return tvl;
    }
};