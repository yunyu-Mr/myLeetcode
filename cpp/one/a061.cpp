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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) return head;
        
        ListNode *p1 = head, *p2 = head;
        // Find length of list.
        int n = 0;
        for (; p2; n++) p2 = p2->next;
        // 
        k = k % n;
        if (k == 0) return head;
        // Two pointers.
        p2 = head;
        while (p2->next && k > 0) {
            p2 = p2->next;
            k--;
        }
        // Move to tail.
        while (p2->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        // Rotate.
        ListNode *newHead = p1->next;
        p1->next = NULL;
        p2->next = head;
        return newHead;
    }
};