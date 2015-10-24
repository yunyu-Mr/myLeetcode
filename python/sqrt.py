class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        l, h = 0, x
        while l <= h:
            m = (l + h) / 2
            if m*m > x:
                h = m-1
            elif m*m < x:
                l = m+1
            else:
                l = h = m
                break
        print "l=%d, h=%d" %(l, h)
        return h

if __name__ == '__main__':
    s = Solution()
    s.mySqrt(10)
