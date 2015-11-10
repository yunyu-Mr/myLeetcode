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
        // Using two queue
        queue<TreeNode*> q1, q2;
        // Result vector
        vector<vector<int>> res;
        
        if (root == nullptr) 
            return res;
        else {
            // push root
            vector<int> vroot;
            vroot.push_back(root->val);
            res.push_back(vroot);
            // push right and left
            q1.push(root->right);
            q1.push(root->left);
        }
        
        TreeNode* t = nullptr;
        
        while (!q1.empty() || !q2.empty()) 
        {
            vector<int> vq1;
            // Pop out queue1 and push all the children into queue2
            while (!q1.empty()) 
            {
                t = q1.front();
                if (t!= nullptr) {
                    vq1.push_back(t->val);
                    q2.push(t->right);
                    q2.push(t->left);
                }
                q1.pop();
            }
            if (!vq1.empty())
                res.push_back(vq1);
            
            vector<int> vq2;
            // Pop out queue2 and push all the children into queue1
            while (!q2.empty()) 
            {
                t = q2.front();
                if (t!= nullptr) {
                    vq2.push_back(t->val);
                    q1.push(t->right);
                    q1.push(t->left);
                }
                q2.pop();
            }
            if (!vq2.empty()) {
                // Reverse the vector queue2
                std::reverse(vq2.begin(), vq2.end());
                res.push_back(vq2);
            }
        }
        return res;
    }
};