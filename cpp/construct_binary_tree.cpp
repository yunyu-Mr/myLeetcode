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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return nullptr;
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, int r1, int t1, vector<int>& inorder, int r2, int t2) {
        
        if (r1 > t1 || r2 > t2 || t1 >= preorder.size() || t2>= inorder.size())  // Termination condition
            return nullptr;
        // printf("r1:%d,t1:%d,r2:%d,t2:%d\n",r1,t1,r2,t2);
        TreeNode *root = new TreeNode(preorder[r1]);  // root
        // cout<<"root->val = "<<root->val<<endl;
        int i = r2;
        for (; i<=t2; i++) {     // find root in inorder list
            if (inorder[i] == preorder[r1]) 
                break;
        }
        
        int sublen = i - r2;
        root->left = buildTree(preorder, r1+1, r1+sublen, inorder, r2, i-1);
        root->right = buildTree(preorder, r1+sublen+1, t1, inorder, i+1, t2);
        
        return root;
    }
};