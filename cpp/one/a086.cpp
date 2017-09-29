/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return head;
        
        ListNode *head1 = NULL, *head2 = NULL, 
                 *curr1 = NULL, *curr2 = NULL,
                 *curr;

        curr = head;
        while (curr != NULL) {
            if (curr->val < x) {
                if (head1 == NULL) {
                    curr1 = head1 = curr;
                }
                else {
                    curr1->next = curr;
                    curr1 = curr1->next;
                }
            }
            else {
                if (head2 == NULL) {
                    curr2 = head2 = curr;
                }
                else {
                    curr2->next = curr;
                    curr2 = curr2->next;
                }
            }
            curr = curr->next;
        }
        //
        if (head1 != NULL && head2 != NULL) {
            curr1->next = head2;    // connect
            curr2->next = NULL;     // set tail
            return head1;
        }
        return head1 == NULL ? head2 : head1;
    }
};