#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
private:
    TreeNode* sortedListToBST(ListNode* head, int length) {
    	// No node
    	if (length == 0)
    		return nullptr;
    	// One node
    	if (length == 1) {
    		TreeNode* root = new TreeNode(head->val);
    		root->left = nullptr;
    		root->right = nullptr;
    		return root;
    	}

    	int mid = length/2;
    	ListNode* curr = head;
    	// Find the mid node
    	for (int i = 0; i < mid; i++) {
    		curr = curr->next;
    	}
    	//cout<<curr->val<<endl;
    	TreeNode* root = new TreeNode(curr->val);
    	root->left = sortedListToBST(head, mid);
    	root->right = sortedListToBST(curr->next, length - mid -1);
    	return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
    	if (head == nullptr) {
    		return nullptr;
    	}

        ListNode *curr = head;

        // Check list length
        int length = 0;
        while (curr != nullptr) {
        	curr = curr->next;
        	length++;
        }
        // reload
        return this->sortedListToBST(head, length);
    }
};