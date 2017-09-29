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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        // Null prev node.
        ListNode *zero = new ListNode(0);
        zero->next = head;
        
        ListNode *prev = zero,
                 *pi = head,
                 *pj = head->next;
        while (pj) {
            if (pi->val == pj->val) {   // Find dup.
                while (pj && pi->val == pj->val)    // skip dup
                    pj = pj->next;
                prev->next = pj;    // remove dup
                pi = pj;
                if (pj) pj = pj->next;
            } else {                // no dup
                prev = prev->next;
                pi = pi->next;
                pj = pj->next;
            }
        }
        return zero->next;
    }
};