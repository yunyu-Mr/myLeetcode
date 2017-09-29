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
    ListNode* reverseBetween(ListNode* head, ListNode* after) {
        if (head == nullptr) return head;
        if (head->next == after) return head;
        
        ListNode *p1 = head,        // point to list that reversed.
                 *p2 = head->next,  // point to list that remained.
                 *p3 = p2->next,    
                 *tail = p1;        // tail of the reversed list.
        // reverse
        while (p3 != after) {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
        }
        p2->next = p1;
        tail->next = after;
        
        return p2;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr)       return head;
        if (head->next == nullptr) return head;
        
        // Between margin.
        ListNode *after = head;
        while (after && n > 0) {
            after = after->next;
            n--;
        }
        // Find the between list.
        ListNode *between = head,
                 *prev = nullptr;
        while (m > 1) {
            prev = between;
            between = prev->next;
            m--;
        }
        // Reverse between list.
        if (prev) prev->next = reverseBetween(between, after);
        else      head = reverseBetween(between, after);
        
        return head;
    }
};