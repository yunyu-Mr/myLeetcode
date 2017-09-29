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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return generateTrees(1, n);
    }
    
    /**
     * Recursive solution.
     * 虽然有重叠子问题，但是所有重叠的子树都需要复制一遍，所以实际上不需要使用DP。
     */
    vector<TreeNode*> generateTrees(int s, int e) {
        vector<TreeNode*> result;
        
        // Stop condition.
        if (s > e) {
            result.push_back(nullptr);
            return result;
        }
        // F(i) = Gen(s, i-1) * Gen(i+1, e)
        for (int i = s; i <= e; i++)
        {
            for (auto left : generateTrees(s, i-1))
                for(auto right : generateTrees(i+1, e))
                {
                    TreeNode *center = new TreeNode(i);
                    center->left = left;
                    center->right = right;
                    result.push_back(center);
                }
        }
        return result;
    }
};