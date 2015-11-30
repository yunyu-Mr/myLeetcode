class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        numsSet = set(nums)
        longest = 0
        for num in nums:
            if num not in numsSet:
                continue
            # Grow upward
            l, k = 0, num+1
            while k in numsSet:
                numsSet.remove(k)
                k += 1
                l += 1
            # Grow downward
            k = num-1
            while k in numsSet:
                numsSet.remove(k)
                k -= 1
                l += 1

            longest = max(longest, l+1)

        return longest


if __name__ == '__main__':
    s = Solution()
    print s.longestConsecutive([1,2,3,3, 100, 200])