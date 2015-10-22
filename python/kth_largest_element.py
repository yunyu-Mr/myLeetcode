import heapq
import random
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # Set up a heap (python default min-heap),
        # so, negative to simulate a max-heap
        heap = [-x for x in nums]
        heapq.heapify(heap)
        # pop out the 1 to k-1 th element
        for i in xrange(1, k):
            heapq.heappop(heap)
        # Return the kth element
        return -heapq.heappop(heap)

class Solution2(object):
    """
    Method 2: Divide and Conquer
    """
    def findKthLargest(self, nums, k):
        return self.randomSelect(nums, k, 0, len(nums)-1)

    def partition(self, nums, p, r):
        i, j = p+1, r
        x = nums[p]  # pivot value
        while True:
            while nums[i] <= x and i < r:
                i += 1
            while nums[j] >= x and j > p:
                j -= 1
            if i >= j:
                break
            # swap, small to left
            nums[i], nums[j] = nums[j], nums[i]
        if i == r and j == p:
            return (p+r)/2
        # nums[j] <= x
        nums[p], nums[j] = nums[j], x
        return j

    def randomPartitoin(self, nums, p, r):
        # partition nums
        # s = random.randint(p, r)
        print "s=%d" %s
        nums[p], nums[s] = nums[s], nums[p]
        return self.partition(nums, p, r)

    def randomSelect(self, nums, k, p, r):
        # print "p=%d, r=%d" %(p, r)
        if p == r:
            return nums[p]
        i = self.randomPartitoin(nums, p, r)
        # print 'i=%d' %i
        n_small = i - p + 1  # number of left part
        if k > n_small:
            return self.randomSelect(nums, k-n_small, i+1, r)
        return self.randomSelect(nums, k, p, i)

if __name__ == '__main__':
    # s = Solution()
    # print s.findKthLargest([0,1,2,3,4,5,6], 2)
    s = Solution2()
    nums = [4,5,2,1,7,9]
    # s.partition(nums, 0, len(nums)-1)
    print s.findKthLargest(nums, 2)
    # print nums