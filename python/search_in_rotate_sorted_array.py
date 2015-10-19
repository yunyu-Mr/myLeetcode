class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # First find the break point( max value)
        brk =self.searchMax(nums, 0, len(nums)-1)

        # Then find target
        pivot = nums[0]
        if target < pivot:
            if brk == len(nums)-1: # in case brk+1 too large
                return -1
            # find in right part
            return self.searchBinary(nums, brk+1, len(nums)-1, target)
        else:
            # find in left part
            # print 'find from %d to %d' %(0, brk)
            return self.searchBinary(nums, 0, brk, target)
        return -1
    
    def searchMax(self, nums, l, r):
        """
        :param nums: list()
        :param l: int
        :param r: int
        :return: index (int)
        """
        pivot = nums[0]
        m = (l+r) / 2
        if nums[m] < pivot: # left
            return self.searchMax(nums, l, m)
        if m+1 == len(nums):
            return m
        elif nums[m] > nums[m+1]:
            return m
        # right
        return self.searchMax(nums, m+1, r)

    def searchBinary(self, nums, l, r, target):
        """
        :param nums: list()
        :param l: int
        :param r: int
        :param target: int
        :return: int
        """
        if l == r:
            if target == nums[l]: # if found, return index
                return l
            return -1  # if not found, return -1
        m = (l+r) / 2
        if target <= nums[m]:
            return self.searchBinary(nums, l, m, target)  #left
        return self.searchBinary(nums, m+1, r, target)    #right


if __name__ == '__main__':
    s = Solution()
    # nums = [4,5,6,7,0,1,2]
    nums = [0,1,2,4,5,6,7]
    print s.searchMax(nums, 0, 6)
    print s.search(nums, 5)
    print s.search(nums, 1)
