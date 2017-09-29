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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head, *curr;
        
        // Init
        if (l1 && l2)
            if (l1->val < l2->val) {
                head = l1;
                l1 = l1->next;
            }else {
                head = l2;
                l2 = l2->next;
            }
        else if (l1 == NULL && l2 == NULL)
            return NULL;
        else if (l1) return l1;
        else         return l2;
        
        curr = head;
        
        // find smaller one each time.
        while (l1 || l2) {
            if (l1 == NULL) {
                curr->next = l2;
                break;
            }else if (l2 == NULL) {
                curr->next = l1;
                break;
            }
            
            // Compare
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }else {
                curr->next = l2;
                l2 = l2->next;
            }
            // move next
            curr = curr->next;
        }
        return head;
    }
};