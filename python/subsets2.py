class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # Sort the input list
        nums.sort()
        # List[subset]
        self.subsets = list()
        self.subsetsTracking(nums, [], 0)
        return self.subsets
        
    def subsetsTracking(self, nums, possible, i):
        if i >= len(nums):
            self.subsets.append(possible)
            return
        # Find the none duplicate point
        j = i + 1
        while j < len(nums) and nums[i] == nums[j]:
            j += 1
        # Add no nums[i]
        self.subsetsTracking(nums, possible, j)
        # Add nums[i]: 1, 2, 3, ... , j-i
        for i in xrange(i, j):
            new_set = possible + nums[i:j]
            self.subsetsTracking(nums, new_set, j)