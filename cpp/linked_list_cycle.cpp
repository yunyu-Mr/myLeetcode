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
		unordered_set<ListNode*> listSet;
		while (head != nullptr) {
			if (listSet.find(head) != listSet.end())
				return true;
			else
				listSet.insert(head);
			head = head->next;
		}
		return false;
    }
};