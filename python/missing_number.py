__author__ = 'smtech'
"""
Missing Number

Tag: bit manipulation
"""
class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        bit = [0 for x in xrange(n+1)]
        for v in nums:
            bit[v] = 1
        miss = 0
        for i in xrange(len(bit)):
            if bit[i] == 0:
                miss = i
                break
        return miss