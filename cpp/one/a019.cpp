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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;
        
        // Two pointer
        ListNode *prev = head, 
                 *tail = head;
        for (int i = 0; i < n && tail; i++)
            tail = tail->next;
        
        if (tail == nullptr) 
            return head->next;
        
        while (tail->next) {
            prev = prev->next;
            tail = tail->next;
        }
        
        // remove
        prev->next = (n == 1) ? nullptr : prev->next->next;
        
        return head;
    }
};