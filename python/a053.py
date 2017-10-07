class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        
        dp = [0 for _ in range(len(nums))]  # DP table, store subarray sum
        maxSub = dp[0] = nums[0]
        
        for i in range(1, len(nums)):
            # Disregard previous sum if less than 0
            dp[i] = (dp[i-1] + nums[i])  if dp[i-1] >= 0 else nums[i]
            maxSub = max(maxSub, dp[i])
        return maxSub