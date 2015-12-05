/*
* Linked List Cycle
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
    bool hasCycle(ListNode *head) {
    	// Using hash set to store checked ListNode
		unordered_set<ListNode*> listSet;
		while (head != nullptr) {
			// if the node has already been checked, there's a loop
			if (listSet.find(head) != listSet.end())
				return true;
			else
				listSet.insert(head);
			head = head->next;
		}
		return false;
    }
};

class Solution2
{
public:
	bool hasCycle(ListNode *head) {
		ListNode *slow = head,
				 *fast = head;
		while (slow != nullptr && fast != nullptr) {
			if (fast->next != nullptr)
				fast = fast->next->next;
			else
			    break;
			slow = slow->next;
			// meet, has cycle
			if (slow == fast)
				return true;
		}
		return false;
	}
	
};