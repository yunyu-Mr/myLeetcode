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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	if (head == nullptr) {
    		return head;
    	}
    	ListNode* empty = new ListNode(0);
    	empty->next = head;
    	head = empty;
        ListNode *pm = head, *pn = head;
        // split 2 pointers
        for (int i=0; i< n-m; i++) 
        {
        	pn = pn->next;
        }
        // 2 pointers run next
        for (int i=1; i < m; i++) {
        	pm = pm->next;
        	pn = pn->next;
	    }
	    // add 2 more pointers record prev(between) and next(between)
	    ListNode* prev = pm;
	    pm = pm->next;
	    pn = pn->next;
	    ListNode* tail = pn->next;
	    // printf("%d, %d\n", pm->val, pn->val);

	    // split out the between linked list
	    pn->next = nullptr;
	    ListNode *p1, *p2;
	    p1 = pm;
	    // reverse the between linked list
	    while (p1->next != nullptr) {
	    	p2 = p1->next;
	    	p1->next = tail;
	    	tail = p1;
	    	p1 = p2;
	    }
	    // rejoin the reversed linked list
	    prev->next = p1;
	    p1->next = tail;

	    head = head->next;
	    delete empty;
	    return head;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	ListNode *head = new ListNode(1);
	ListNode *curr = head;
	for (int i = 2; i < 6; ++i)
	{
		curr->next = new ListNode(i);
		curr = curr->next;
	}
	curr = s.reverseBetween(head, 1, 1);
	while (curr != nullptr) {
		printf("%d\n", curr->val);
		curr = curr->next;
	}
	return 0;
}