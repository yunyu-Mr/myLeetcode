/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr)
            return new TreeNode(head->val);
        
        ListNode *step1, *step2;
        step1 = head;
        step2 = head->next;
        
        // Find the mid break point.
        while (step2) {
            step2 = step2->next;
            if (step2)
                step2 = step2->next;
            if (step2)
                step1 = step1->next;
        }
        
        ListNode *prev = step1,         // break point
                 *right = step1->next;  // right sub list
        prev->next = nullptr;  // cut the list
        
        TreeNode *root = new TreeNode(right->val);  // root node
        
        if (right != head)
            root->left = sortedListToBST(head);     // left sub tree
        if (right->next)
            root->right = sortedListToBST(right->next); // right sub tree
        
        return root;
    }
};