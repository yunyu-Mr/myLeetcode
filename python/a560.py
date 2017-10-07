class Solution(object):
    def subarraySum(self, nums, k):
        """
        sum(i,j) = sum(0,j) - sum(0,i)
        
        Count all k = sum(i,j)
        
        Use a hash table to record the frequency of (currentSum - k)
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        sumTable = collections.defaultdict(lambda: 0) # Hash table, {prefixSum: frequency}
        sumTable[0] = 1
        
        prefixSum = 0; count = 0    # prefixSum = sum(0, i)
        for num in nums:
            prefixSum += num
            # Find how many sum(0,i) = sum(0,j) - k.
            # If not exist, count += 0
            count += sumTable[prefixSum - k]  
            # Count sum(0,j)
            sumTable[prefixSum] += 1
        return count