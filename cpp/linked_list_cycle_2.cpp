/*
* Linked List Cycle 2
*/
#include <iostream>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Using hash set to store checked ListNode
		unordered_set<ListNode*> listSet;
		while (head != nullptr) {
			// if the node has already been checked, there's a loop
			if (listSet.find(head) != listSet.end())
				return head; // return where the cycle begin
			else
				listSet.insert(head);
			head = head->next;
		}
		return nullptr;
    }
};