class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) <= 1:
            return [nums]
        
        nums.sort()
        res = list()
        res.append(nums[:])
        while True:
            i = len(nums) - 1
            j = i - 1
            while nums[i] <= nums[j] and j>= 0:  # Find nums[i] > nums[j]
                i, j = i-1, j-1
            if j < 0:
                break
            i = len(nums) -1
            while nums[i] <= nums[j]:   # Find nums[i] > nums[j]
                i -= 1
            # nums[i] merely bigger than nums[j]
            nums[i], nums[j] = nums[j], nums[i]
            
            i = len(nums) - 1
            k = j+1
            while k < i:
                nums[k], nums[i] = nums[i], nums[k]
                k, i = k+1, i-1
            print nums
            res.append(nums[:])
        return res

if __name__ == '__main__':
    s = Solution()
    print s.permute([1,1,2])