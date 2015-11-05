class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0:
            return 0

        # Max profit from left to right
        leftprof = [0 for x in xrange(len(prices))]
        lowest = prices[0]
        for i in xrange(1,len(prices)):
            leftprof[i] = max(leftprof[i-1], prices[i]-lowest)
            lowest = min(lowest, prices[i])

        # Max profit from right to left
        rightprof = [0 for x in xrange(len(prices))]
        highest = prices[-1]
        for i in xrange(len(prices)-2, -1, -1):
            rightprof[i] = max(rightprof[i+1], highest - prices[i])
            highest = max(highest, prices[i])

        # Break from middle. Left part max + right part max
        max_profit = 0
        for i in xrange(len(prices)):
            max_profit = max(max_profit, rightprof[i]+leftprof[i])
        return max_profit

if __name__ == '__main__':
    s = Solution()
    print s.maxProfit([1,7,3,10,2,3,5])