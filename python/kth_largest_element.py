import heapq
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

if __name__ == '__main__':
    s = Solution()
    print s.findKthLargest([0,1,2,3,4,5,6], 2)