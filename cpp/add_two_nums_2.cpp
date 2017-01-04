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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *p1 = l1, *p2 = l2, *head, *curr;
        
        head = new ListNode(0);
        curr = head;
    
        while (p1 != nullptr || p2 != nullptr) {
            int s;
            if (p1 == nullptr) {
                s = p2->val + carry;
                p2 = p2->next;
            }else if (p2 == nullptr) {
                s = p1->val + carry;
                p1 = p1->next;
            }else {
                s = p1->val + p2->val + carry;
                p1 = p1->next; p2 = p2->next;
            }
            carry = s / 10;
            curr->next = new ListNode(s % 10);
            curr = curr->next;
        }
        if (carry) curr->next = new ListNode(1);
        return head->next;
    }
};