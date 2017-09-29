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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        
        auto cmp = [](const ListNode* left, const ListNode* right) {return left->val > right->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        
        // Init pq
        for (ListNode* head : lists) {
            if (head != nullptr) 
                pq.push(head);
        }
        
        if (pq.empty()) return nullptr;
        
        // init pointer
        ListNode *head = nullptr, *curr;
        head = pq.top(); pq.pop();
        if (head->next != nullptr) pq.push(head->next);
        curr = head;
        
        while (!pq.empty()) {
            curr->next = pq.top(); pq.pop();
            curr = curr->next;
            if (curr->next != nullptr)
                pq.push(curr->next);
        }
        return head;
    }
};