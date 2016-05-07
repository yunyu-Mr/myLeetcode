# -*- coding:utf-8 -*-  
"""
H-Index

A scientist has index h if h of his/her N papers have at least h citations each, 
and the other N − h papers have no more than h citations each.

Solution: Find the point which citations[i] merely larger than h[i],
            h = [N, N-1, ... , 2, 1]
            
Time: O(log n)
"""
class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        N = len(citations)
        if N == 0:
            return 0
            
        # Binary search.
        l, r = 0, N-1
        while l < r:
            i = (l+r) / 2
            hi = N - i
            if citations[i] < hi:
                l = i + 1
            if citations[i] >= hi:
                r = i
        # Check the final.
        if citations[l] < (N - l):
            return N - l - 1
        return N - l