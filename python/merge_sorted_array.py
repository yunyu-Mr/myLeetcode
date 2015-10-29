class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        max_len = m + n
        i, j = m-1, n-1
        # Merge from max to min
        for k in xrange(max_len-1, -1, -1):
            if i >= 0 and j >= 0:
                if nums1[i] > nums2[j]:
                    nums1[k] = nums1[i]
                    i -= 1
                else:
                    nums1[k] = nums2[j]
                    j -= 1
            else:
                # If one of the nums is empty, break
                break

        # Check the rest of nums
        if j < 0:
            return
        if i < 0:
            while j >= 0:
                nums1[k] = nums2[j]
                j -= 1
                k -= 1
            return

if __name__ == '__main__':
    s = Solution()
    nums = [4,5,6,0,0,0,0]
    s.merge(nums, 3, [1,2,3], 3)
    # nums = [2,0]
    # s.merge(nums, 1, [1], 1)
    print nums