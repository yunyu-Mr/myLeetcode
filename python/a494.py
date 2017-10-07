class Solution(object):
    def findTargetSumWays(self, nums, S):
        """
        [1, 1, 1, 1, 1]; S = 3
        
        {1:1, -1:1}
        {2:1, 0:2, -2:1}
        {3:1, 1:3, -1:3, -3:1}
        {4:1, 2:4,  0:6, -2:4, -4:1}
        {5:1, 3:5,  1:10,-1:10,-3:5, -5:1}
        
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        cnt = collections.Counter()
        cnt[nums[0]]  += 1
        cnt[-nums[0]] += 1
        
        for num in nums[1:]:
            newCnt = collections.Counter()
            for k, v in cnt.items():
                newCnt[k + num] += v
                newCnt[k - num] += v
            cnt = newCnt
        return cnt[S]