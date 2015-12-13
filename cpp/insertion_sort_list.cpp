/*
 *  Insertion Sort List
 */


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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr)
            return head;
        
        ListNode* prev_c = head;
        ListNode* curr = head->next;
        while (curr != nullptr)
        {
            ListNode *scan = head, *prev_s = nullptr;
            while (scan != curr) 
            {
                // Find the insert point
                if (curr->val <= scan->val)
                    break;
                else {
                    prev_s = scan;
                    scan = scan->next;
                }
            }
            
            if (scan != curr){
                // Delete curr
                prev_c->next = curr->next;
                // Insert curr
                if (prev_s != nullptr) {
                    // Insert at mid
                    prev_s->next = curr;
                    curr->next = scan;
                }else {
                    // Insert at head
                    curr->next = scan;
                    head = curr;
                }
                curr = prev_c->next;
            } 
            else {
                // Nothing change, move next
                prev_c = curr;
                curr = curr->next;   
            }
        }
        
        return head;
    }
};