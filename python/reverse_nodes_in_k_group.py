# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    """
    Recursive reverse
    First reverse the K nodes front.
    Then reverse the rest nodes recursively.
    """
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if k == 1:
            return head
        return self.reverseNextGroup(head, k)

    def reverseNextGroup(self, head, k):
        """
        :param head: ListNode
        :param k:  int
        :return: ListNode
        """
        if not head:
            return head

        new_end = head
        for i in xrange(1, k):
            if head.next:
                head = head.next
            else:
                return head
        p1 = new_end
        p2 = p1.next
        while p2 != head:
            tmp = p1
            p1 = p2
            p2 = p2.next
            p1.next = tmp
        # p2 == start
        new_end.next = self.reverseNextGroup(p2.next, k)
        p2.next = p1
        return head

if __name__ == '__main__':
    s = Solution()
    head = ListNode(1)
    curr = head
    for i in xrange(2, 7):
        curr.next = ListNode(i)
        curr = curr.next
    head = s.reverseKGroup(head, 3)
    curr = head
    while curr:
        print curr.val
        curr = curr.next