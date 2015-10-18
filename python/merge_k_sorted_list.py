# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if len(lists) == 0:
            return None
        return self.mergeKSubLists(lists, 0, len(lists)-1)

    def mergeKSubLists(self, lists, l, r):
        if l == r:
            # print 'l=',l
            return lists[l]
        m = (l+r) / 2
        left = self.mergeKSubLists(lists, l, m)
        right = self.mergeKSubLists(lists, m+1, r)
        return self.mergeLists(left, right)

    def mergeLists(self, left, right):
        """
        :param left: ListNode
        :param right: ListNode
        :return: ListNode
        """
        curr = ListNode(0)
        head = curr
        l = left
        r = right
        while l or r:
            if l and r:
                if l.val < r.val:
                    curr.next = l
                    l = l.next
                else:
                    curr.next = r
                    r = r.next
            elif l:
                curr.next = l
                l = l.next
            else:
                curr.next = r
                r = r.next
            curr = curr.next
        # print 'head.next.val=', head.next.val
        return head.next

if __name__ == '__main__':
    s = Solution()
    lists = [ListNode(i) for i in range(4)]
    for i in xrange(len(lists)):
        lists[i].next = ListNode(i+len(lists))
    l = s.mergeKLists(lists)
    while l:
        print l.val
        l = l.next
