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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        if (head->next == nullptr) return head;
        
        ListNode *p1 = head->next,
                 *p2 = head->next->next;
        
        p1->next = head;
        head->next = swapPairs(p2);
        
        return p1;
    }
};