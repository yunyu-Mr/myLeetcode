class Solution(object):
    def __init__(self):
        self.max_profit = 0

    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) <= 1:
            return 0

        diff = [0 for x in xrange(len(prices))]
        for i in xrange(1, len(prices)):
            diff[i] = prices[i] - prices[i-1]

        i = 1
        j = 0
        while k > 1 and i < len(diff):
            while i < len(diff) and diff[i] < 0:
                i += 1
            while i < len(diff) and diff[i] > 0:
                i += 1
            # if can not find a peak point, break
            if i == len(diff):
                break
            self.max_profit += self.maxProfit1(prices, j, i)
            j = i-1
            k -= 1

        print self.max_profit + self.maxProfit1(prices, j, len(prices))

    def maxProfit1(self, prices, j, i):
        """
        :type prices: List[int]
        :rtype: int
        """
        if i-j == 0:
            return 0
        # profit = 0
        profits = [0 for x in xrange(i-j)]
        lowest = prices[j]
        for k in xrange(1, i-j):
            profits[k] = max(profits[k-1], prices[j+k]-lowest)
            lowest = min(lowest, prices[j+k])
        return profits[-1]

if __name__ == '__main__':
    s = Solution()
    s.maxProfit(2, [4,2,3,3,5,2,1,9])