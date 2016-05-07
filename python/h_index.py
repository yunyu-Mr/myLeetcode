# -*- coding:utf-8 -*-  
"""
H-Index

A scientist has index h if h of his/her N papers have at least h citations each, 
and the other N − h papers have no more than h citations each.
"""
class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        O(n * log n)
        """
        # Sort the citations list.
        citations.sort()
        
        # Check from large to small.
        h = 0
        for idx in citations[::-1]:
            if idx > h:
                h += 1
            else :
                break
        return h
        
if __name__ == '__main__':
    s = Solution()
    print s.hIndex([3, 0, 6, 1, 5])
    print s.hIndex([0])
    print s.hIndex([1])
    print s.hIndex([0,0])