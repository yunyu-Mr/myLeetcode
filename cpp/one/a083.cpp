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
        if (head == NULL) return head;
        
        ListNode *pi = head, *pj = head->next;
        while (pj) {
            // Skip dup node.
            while (pj && pi->val == pj->val)
                pj = pj->next;
            // Remove dup.
            pi->next = pj;
            // Next
            pi = pj;
            if (pj) pj = pj->next;
        }
        return head;
    }
};