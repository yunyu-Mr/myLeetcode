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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag;
        if (root == nullptr) return zigzag;
        
        int level = 0;
        stack<TreeNode*> s0, s1;
        s0.push(root);
        
        while (!s0.empty() || !s1.empty())
        {
            stack<TreeNode*> &sc = level % 2 == 0 ? s0 : s1,
                             &se = level % 2 == 0 ? s1 : s0;
            
            if (level >= zigzag.size())         // new level
                zigzag.push_back(vector<int>());
                
            while (!sc.empty()) {               // traversal a level.
                TreeNode *node = sc.top();
                sc.pop();
                
                zigzag[level].push_back(node->val);  // visit
                
                // Next level children
                TreeNode *first  = level %2 == 0? node->left : node->right,
                         *second = level %2 == 1? node->left : node->right;
                if (first)  se.push(first);
                if (second) se.push(second);
            }
            
            level++;
        }
        return zigzag;
    }
};