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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        
        ListNode *slow = head,
                 *fast = head;
        
        if (!slow) return false;
        else slow = slow->next;
        
        if (!slow) return false;
        else fast = slow->next;
        
        while (slow != fast) {
            if (!fast) return false;
            else       fast = fast->next;
            if (!fast) return false;
            else       fast = fast->next;
            
            if (!slow) return false;
            else       slow = slow->next;
        }
        return true;
    }
};