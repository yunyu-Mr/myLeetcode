# Max Gap
#
# Based on Radix Sort

class Solution(object):
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 1:
            return 0

        # Radix Sort
        # Each integer is 32 bits. I divided each int into 8 parts, each part 4 bits.
        # Time: O(32/4 *(n+2^4)) = O(8*(n+16)) = O(n)
        for x in xrange(0,8):
            d = 15 << 4*x   # filter, choose which bits would be sorted
            bucket = [[] for m in xrange(16)]
            for num in nums:
                b = (num & d) >> 4*x    # filtering the parts of bits
                bucket[b].append(num)   # map to bucket
            nums = []   # clear
            for section in bucket:
                nums += section     # reordered

        # Find max gap
        gap = 0
        for i in xrange(1, len(nums)):
            gap = max(gap, nums[i] - nums[i-1])
        return gap

if __name__ == '__main__':
    s = Solution()
    print s.maximumGap([2,1,1024,4096,10,128,512])