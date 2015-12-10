#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
private:
	/*
	 * Reverse List
	 */
	ListNode* reverseList(ListNode* head, ListNode* tail) {
		// if only one node, return
		if (head == nullptr || head->next == nullptr)
			return head;

		// Use 3 pointers
		ListNode *p1 = head,
				 *p2 = head->next;
		ListNode *p3 = p2->next;

		p1->next = nullptr; // head become tail
		while (p3 != nullptr) 
		{
			p2->next = p1;
			p1 = p2;
			p2 = p3;
			p3 = p3->next;
		}
		p2->next = p1; // tail become head

		return tail;
	}

	/*
	 * Just travel and print the ListNode.
	 */
	void travel(ListNode * head) {
		while (head != nullptr) {
    		cout<<head->val<<"\t";
    		head = head->next;
    	}
    	cout<<endl;
	}

public:
    void reorderList(ListNode* head) {
    	int n = 0; // length
    	ListNode *curr = head, *tail;
    	// find length
    	while (curr != nullptr) {
    		tail = curr;
    		curr = curr->next;
    		n++;
    	}

    	// Find the break point
    	int mr = (n+1)/2;
    	ListNode* prev = nullptr;
    	curr = head;
    	for (int i = 0; i < mr; i++) {
    		prev = curr;
    		curr = curr->next;
    	}

    	// Reverse right list
    	curr = reverseList(curr, tail);

    	// Cut the list into 2 part
    	if (prev != nullptr)
    		prev->next = nullptr;


    	// Interleaving 2 list
    	ListNode *p1 = head, 
    			 *p2 = curr;
    	curr = head;
    	while (p2 != nullptr) {
    		p1 = p1->next;
    		curr->next = p2;
    		p2 = p2->next;
    		curr = curr->next;
    		curr->next = p1;
    		curr = curr->next;
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	ListNode *head = new ListNode(1), *curr;
	curr = head;
	for (int i = 2; i < 8; i++) {
		curr->next = new ListNode(i);
		curr = curr->next;
	}
	s.reorderList(head);

	return 0;
}