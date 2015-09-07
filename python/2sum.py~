class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashtb = dict() # hash table
        for i in xrange(len(nums)):
            diff = target - nums[i]
            # if you can find diff at hash table, return 
            if diff in hashtb:
                return [hashtb.get(diff)+1, i+1]
            else:   # if you can't find diff, add to hash table
                hashtb[nums[i]] = i
            
        return []
