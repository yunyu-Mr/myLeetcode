/*
 *	Intersection of two Linked List
 *
 *	Time: O(n);		Space: O(1);
 *	First pass:	travel the shorter list;
 *  Second pass: cutting the longer list, two list start from the same length.
 *	Last pass: compare the rest of two lists.
 */

#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
        	return nullptr;

        ListNode *currA = headA,
        		 *currB = headB;
        // Pass the shorter list.
        while (currA != nullptr && currB != nullptr) {
        	currA = currA->next;
        	currB = currB->next;
        }
        ListNode *curr = nullptr, *p1 = headA, *p2 = headB;
        if (currA != nullptr) {
        	curr = currA;
        	p1 = headA;
        	p2 = headB;
        }
        else if (currB != nullptr) {
        	curr = currB;
        	p1 = headB;
        	p2 = headA;
        } 

        // Cutting the longer list
        while (curr != nullptr) {
        	curr = curr->next;
        	p1 = p1->next;
        }

        // Compare
        while (p1 != p2 && p1 != nullptr) {
        	p1 = p1->next;
        	p2 = p2->next;
        }
        return p1;

    }
};

int main(int argc, char const *argv[])
{
	ListNode *headA = new ListNode(1);
	ListNode *headB = new ListNode(0);
	ListNode *currA = headA, *currB = headB;
	for (int i = 2; i < 10; ++i)
	{
		currA->next = new ListNode(i);
		currA = currA->next;
		if (i == 5)
			currB->next = currA;
	}
	Solution s;
	ListNode *p = s.getIntersectionNode(headA, headB);
	if (p != nullptr)
		cout<<p->val<<endl;
	return 0;
}