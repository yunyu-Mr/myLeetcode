/*
 * Sort List
 * 
 * Using Merge Sort
 * T(n) = 2*T(n/2) + O(n)
 * Thus, O(n log(n))
 */

 #include <iostream>
 #include <vector>
 using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        	return head;
        
        ListNode *curr = head, *prev = nullptr, *fast = head;
        while (fast != nullptr) {
        	prev = curr;
        	// slow pointer, stay at mid
        	curr = curr->next;
        	// fast pointer, stop at tail
        	fast = fast->next;
        	if (fast != nullptr)
        		fast = fast->next;
        	else
        		break;
        }
        // Cut list
        prev->next = nullptr;

        //Sort left list
        ListNode *left = sortList(head);
        //Sort right list
        ListNode *right= sortList(curr);

        // left start with the smallest element
        if (left->val > right->val) {
        	ListNode *tmp = left;
        	left = right;
        	right = tmp;
        }

        // Insert the right list to the left list
        prev = left;
        curr = left->next;
        while (curr != nullptr) 
        {
        	if (curr->val > right->val) 
        	{
        		prev->next = right;

        		ListNode *prev2 = right,
        				 *curr2 = prev2->next;
        		while (curr2 != nullptr) 
        		{
        			if (curr->val > curr2->val) 
        			{
        				curr2 = curr2->next;
        				prev2 = prev2->next;
        			}else {
        				break;
        			}
        		}
        		prev2->next = curr;
        		right = curr2;
        		if (right == nullptr)
        			break;
        	}
        	prev = curr;
        	curr = curr->next;
        }

        // left list scan to tail, append right list
        if (curr == nullptr)
        	prev->next = right;

        return left;  // left is head now
    }

 //    void printList(ListNode* head) {
 //    	ListNode *curr = head;
 //    	while (curr != nullptr){
	// 		cout<<curr->val<<" ";
	// 		curr = curr->next;
	// 	}
	// 	cout<<endl;
	// }
};

int main(int argc, char const *argv[])
{
	vector<int> array = {3,2,7,1,9};
	ListNode *head = new ListNode(array[0]);
	ListNode *curr = head;
	for (int i = 1; i < array.size(); ++i)
	{
		curr->next = new ListNode(array[i]);
		curr = curr->next;
	}

	Solution s;
	head = s.sortList(head);

	while (head != nullptr){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;

	return 0;
}