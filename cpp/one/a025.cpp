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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return head;
        if (head->next == nullptr) return head;
        
        ListNode *head2 = nullptr, *prev;
        // Find cut point.
        prev = head;
        int i = 1;
        while (i < k && prev->next != nullptr){
            prev = prev->next;
            i++;
        }
        if (i < k) return head;  // over list
        
        head2 = prev->next;    // second list
        prev->next = nullptr;  // cut
        
        // Recursive reverse.
        head2 = reverseKGroup(head2, k);
        
        ListNode *next = head->next;
        while (next != nullptr) {
            head->next = head2;
            head2 = head;
            head = next;
            next = next->next;
        }
        head->next = head2;
        
        return head;
    }
};