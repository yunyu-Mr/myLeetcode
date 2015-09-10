# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None or head.next == None:
            return head
        p1 = head
        p2 = head.next
        pre = ListNode(0) # previous node
        pre.next = head
        head = pre        # fake header
        while True:
            # swap 2 node
            pre.next = p2
            p1.next = p2.next
            p2.next = p1
            pre = p1
            # if only 1 node or non node left, break and finish
            if p1.next == None: 
                break
            elif p1.next.next==None:
                break
            # shift to next
            p1 = p1.next
            p2 = p1.next
        return head.next # first node is a fake header
        
