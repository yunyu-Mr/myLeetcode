class MedianFinder(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.minh = []  # Min heap (right)
        self.maxh = []  # Max heap (left)
        self.size = 0   # min size + max size ( len(minh) = len(maxh) + 1 )

    def addNum(self, num):
        """
        :type num: int
        :rtype: void
        """
        import heapq as hq
        
        if self.size %2 == 0:  # Even, insert into minh
            if len(self.maxh) > 0 and num < -self.maxh[0]:  # Ensure left < right
                hq.heappush(self.maxh, -num)
                num = -hq.heappop(self.maxh)
            hq.heappush(self.minh, num)
        else:                       # Odd, insert into maxh
            if num > self.minh[0]:  # Ensure left < right
                hq.heappush(self.minh, num)
                num = hq.heappop(self.minh)
            hq.heappush(self.maxh, -num)
            
        self.size += 1
            

    def findMedian(self):
        """
        :rtype: float
        """
        if self.size %2 == 1:      # Odd
            median = self.minh[0]
        else:                      # Even
            median = (-self.maxh[0] + self.minh[0]) / 2.0
        return median


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()