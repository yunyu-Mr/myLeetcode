class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        n = len(nums)
        
        nums = sorted(nums)
        
        diff = 1000000
        output = 0
        for i in xrange(n-2):
            low = i + 1
            high = n - 1
            while low < high:
                s = nums[low] + nums[high] + nums[i]
                if  abs(target - s) < diff:
                    diff = abs(target-s)
                    output = s
                if (target < s):
                    high -= 1
                else:
                    low += 1
        
        return output