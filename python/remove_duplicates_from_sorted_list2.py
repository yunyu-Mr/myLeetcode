# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head
        if not head.next:
            return head
        # Add an empty node which is for convenience
        prev = ListNode(head.val - 1)
        prev.next = head
        curr = head
        head = prev
        # No duplicates, both prev and curr pass.
        while curr.next and curr.val != curr.next.val:
            prev = prev.next
            curr = curr.next
        # Find duplicates, fix prev and move curr.
        while curr.next and curr.val == curr.next.val:
            curr = curr.next

        # Escape several nodes between prev and curr;
        # If no nodes between them, please don't escape.
        if prev.next != curr:
            prev.next = self.deleteDuplicates(curr.next)

        return head.next

if __name__ == '__main__':
    s = Solution()
    head = ListNode(1)
    curr = head
    curr.next = ListNode(1)
    curr = curr.next
    curr.next = ListNode(2)
    curr = curr.next
    curr.next = ListNode(3)
    curr = curr.next
    curr.next = ListNode(5)

    p = s.deleteDuplicates(head)
    while p:
        print p.val
        p = p.next