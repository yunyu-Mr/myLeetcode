#include <iostream>
#include <queue>
using namespace std;

//Definition for binary tree with next pointer.
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if (root == nullptr)
    		return;

        queue<TreeLinkNode*> q;

        //Init
        root->next = nullptr;
        q.push(root);
        q.push(nullptr);

        TreeLinkNode* curr;
        while (!q.empty()) {
        	curr = q.front();
        	q.pop();
        	if (curr == nullptr){  // null: 1. break point; or 2. terminate point
        	    if (q.empty())  //empty, terminate
        	        break;
        	    if (q.front() == nullptr)  // followint another null (2 nulls), terminate.
        	        break;
        	    continue;  //If it is only a single null, it's break point, continue;
        	}
        	if (curr->left != nullptr) 
        		q.push(curr->left);
            if (curr->right != nullptr)
        		q.push(curr->right);
        	
        	curr->next = q.front();     //point to next
        	if (q.front() == nullptr)
        	    q.push(nullptr);        //create another break point
        }
    }
};

int main(int argc, char const *argv[])
{
	TreeLinkNode* head = new TreeLinkNode(1);
	head->left = new TreeLinkNode(2);
	head->right = new TreeLinkNode(3);
	Solution s;
	s.connect(head);
	return 0;
}