"""
House Robber I
"""
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        if len(nums) <3:
        	return max(nums)
        s = list()
        s.append(nums[0])
        s.append(max(nums[:2]))
        max_rob = 0
        for i in xrange(2,len(nums)):
        	max_rob = max(s[i-2]+nums[i], s[i-1])
        	s.append(max_rob)
        return max_rob

if __name__ == '__main__':
	s = Solution()
	print s.rob([1,1,1,2])