/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    	if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode * left = new ListNode(0), *right = head;
        left->next = head;
        head = left;
        while (right->val < x) {
        	if (right->next == nullptr) {
        		break;
        	}else {
        		right = right->next;
        	}
        	left = left->next;
        }
        // printf("find the partition point: left=%d, right=%d\n", left->val, right->val);
        ListNode *prev = right, *curr = right->next;
        while (curr != nullptr) {
        	if (curr->val >= x) {
        		curr = curr->next;
        		prev = prev->next;
        	} else {
        		// right part pass it
        		prev->next = curr->next;
        		// left part add it
        		left->next = curr;
        		left = left->next;
        		// fresh prev and curr
        		curr = prev->next;
        	}
        }

        left->next = right;
        return head->next;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	ListNode *head = new ListNode(1), *curr;
	curr = head;
	curr->next = new ListNode(4);
	curr = curr->next;
	curr->next = new ListNode(3);
	curr = curr->next;
	curr->next = new ListNode(2);
	curr = curr->next;
	curr->next = new ListNode(2);

	curr = s.partition(head, 5);
	while (curr != nullptr) {
		cout<<curr->val<<" -> ";
		curr = curr->next;
	}
	cout<<endl;
	return 0;
}