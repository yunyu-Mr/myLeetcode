/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
typedef RandomListNode RLNode;

class Solution {
public:
    RLNode *copyRandomList(RLNode *head) {
        if (!head) return NULL;
        
        unordered_map<RLNode*, RLNode*> copyTable;
        
        RLNode * head2 = new RLNode(head->label);
        copyTable[head] = head2;
        
        // First copy list
        for (RLNode *p = head, *p2 = head2;
             p->next != NULL;
             p = p->next, p2 = p2->next)
        {
            p2->next = new RLNode(p->next->label);
            copyTable[p->next] = p2->next;
        }
        // Then copy random pointer
        for (RLNode *p = head, *p2 = head2;
             p != NULL;  // attention
             p = p->next, p2 = p2->next)
        {
            if (p->random)
                p2->random = copyTable[p->random];
        }
        
        return head2;
    }
};