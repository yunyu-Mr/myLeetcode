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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        
        ListNode *slow = head,
                 *fast = head;
        
        if (!slow) return nullptr;
        else slow = slow->next;
        
        if (!slow) return nullptr;
        else fast = slow->next;
        
        while (slow != fast) {
            if (!fast) return nullptr;
            else       fast = fast->next;
            if (!fast) return nullptr;
            else       fast = fast->next;
            
            if (!slow) return nullptr;
            else       slow = slow->next;
        }
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        return slow;
    }
};