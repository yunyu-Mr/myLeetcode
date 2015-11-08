/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/*
 * Two situations.
 * 
 * Suppose tree [5,3,7,2,4,6,8]
 *             5
 *       3           7
 *     2   4       6   8
 *
 * 1. Swap one node in left subtree , and one in right subtree. You would find 2 nodes' value less than previous'.
 *    For example, swap 2, 6.  Result: [6*,3,4,5,2*,7,8]
 *    Attention, swap root and one in left is the same as above.
 *
 * 2. Swap root and one node in right subtree. You would only find 1 node less than previous.
 *    For example, swap 5 and 4. Result: [2,3,5*,4*,6,7,8]
 */
class Solution {
private:
	stack<TreeNode*> trace;
	// In order transversal and push into stack
	void inOrderTrace(TreeNode* root) {
		if (root == nullptr) return;
		inOrderTrace(root->left);
		this->trace.push(root);
		inOrderTrace(root->right);
	}
public:
    void recoverTree(TreeNode* root) {
    	if (root == nullptr) return;

    	// Push in stack and pop out in decreasing order.
    	this->inOrderTrace(root);
    	
    	TreeNode *first = nullptr, *second = nullptr;
    	TreeNode* curr = this->trace.top();
    	this->trace.pop();

    	while (!this->trace.empty()) 
    	{
    		// Must in decreasing order. If not, wrong and track it.
    		if (curr->val < (trace.top())->val) {
    			if (first == nullptr) 
    			{
    				first = curr;
    				second = trace.top();
    			}
    			else
    			{
    				second = trace.top();
    				break;
    			}
    		}
    		curr = trace.top();
    		trace.pop();
    	}
    // 	std::cout<<"first: "<<first->val<<" second: "<<second->val;
    	// Swap and recover:
    	int tmp = first->val;
    	first->val = second->val;
    	second->val = tmp;
    }
};