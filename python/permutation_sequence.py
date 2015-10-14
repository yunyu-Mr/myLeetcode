class Solution(object):
    def __init__(self):
        self.fac = [1]
        self.res = []
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        for i in xrange(2,n+1):
            self.fac.append(i*self.fac[i-2])
        nums = [x for x in xrange(1, n+1)]
        self.perm(nums, n, k)
        return ''.join([str(x) for x in self.res])

    def perm(self, nums, n, k):
        # print 'k=',k
        if n == 1:
            self.res.append(nums[0])
            return
        r = (k-1) / self.fac[n-2] + 1
        self.res.append(nums[r-1])
        if (r-1)==0:
            new_nums = nums[1:]
        elif (r-1) == n-1:
            new_nums = nums[:n]
        else:
            new_nums = nums[:r-1] + nums[r:]
        return self.perm(new_nums, n-1, k - (r-1)*self.fac[n-2])

if __name__ == '__main__':
    s = Solution()
    print s.getPermutation(4, 11)