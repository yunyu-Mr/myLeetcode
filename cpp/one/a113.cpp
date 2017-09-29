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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        
        dfs(res, path, root, sum);
        
        return res;
    }
    
    void dfs(vector<vector<int>> &res, vector<int> &path, TreeNode *root, int sum) {
        if (root == nullptr) return;

        sum -= root->val;
        path.push_back(root->val);
        
        if (sum == 0 && root->left == nullptr && root->right == nullptr) {
            res.push_back(path);
            path.pop_back();
            return;
        }
        
        dfs(res, path, root->right, sum);
        dfs(res, path, root->left, sum);
        path.pop_back();
    }
};