__author__ = 'smtech'
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        N = len(nums)
        new_nums = [0 for x in xrange(N+1)]
        for i in xrange(N):
            # nums[i] should be from 1 to N
            if nums[i] <= N and nums[i] > 0:
                new_nums[nums[i]] = nums[i]
        for i in xrange(1, N+1):
            if new_nums[i] != i:
                return i
        return N+1

if __name__=='__main__':
    s = Solution()
    print s.firstMissingPositive([3,4,-1,1])