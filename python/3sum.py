class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        # ATTENTIONS!
        # Pass duplicte item in order to speed up algorithm!
        
        n = len(nums)
        if n < 3:
            return []
        
        # sort list. n*log n
        nums.sort()
        
        triplets = list() # output list
        triplet = list()  # triple
        
        s = 0
        low = 0  # two pointers
        high = 0
        for i in xrange(n-2):
            if i>0 and nums[i] == nums[i-1]:  # pass duplicate
                continue
            low = i+1
            high = n-1
            while low < high:
                s = nums[i] + nums[low] + nums[high]
                if s == 0:
                    triplet = [nums[i],nums[low],nums[high]]
                    triplets.append(triplet)
                    while low < high and nums[low] == nums[low+1]: # pass duplicate
                        low += 1
                    while low < high and nums[high] == nums[high-1]: # pass duplicate
                        high -= 1
                if s < 0:
                    low += 1
                else:
                    high -= 1
                
                
        return triplets