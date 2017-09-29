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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums, int i, int j) {
        if (i > j) return nullptr;
        
        int k = (i + j + 1) / 2;    // left tree < root; right tree >= root.
        
        TreeNode *root = new TreeNode(nums[k]);

        root->left = sortedArrayToBST(nums, i, k-1);
        root->right = sortedArrayToBST(nums, k+1, j);
        
        return root;
    }
};