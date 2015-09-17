class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if len(nums) <= 1:
            return

        i = len(nums) -1
        j = i - 1
        while nums[i] <= nums[j] and j >=0:
            j -= 1
            i -= 1
        if j >= 0:
            i = len(nums) -1
            while nums[j] >= nums[i]:
                i -= 1
            nums[i], nums[j] = nums[j], nums[i]
            k = j +1
        else:
            k = 0
        
        i = len(nums) -1
        while k < i:
            nums[k], nums[i] = nums[i], nums[k]
            k += 1
            i -= 1