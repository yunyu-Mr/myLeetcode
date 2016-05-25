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
    vector<string> allPaths;
    
    void travel(TreeNode* root, const std::string &path) {
        ostringstream oss;
        // is leaf
        if (root->left == nullptr && root->right == nullptr) {
            oss << path << root->val;
            allPaths.push_back(oss.str());
            return;
        }
        oss << path << root->val << "->";
        
        if (root->left != nullptr) 
            travel (root->left, oss.str());
        if (root->right != nullptr)
            travel (root->right, oss.str());
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr)
            return allPaths;
        
        travel(root, "");
        
        return allPaths;
    }
};