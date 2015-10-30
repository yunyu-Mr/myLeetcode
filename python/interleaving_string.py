class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        n1, n2 = len(s1), len(s2)
        m = [[False for col in xrange(1+n2)] for row in xrange(1+n1)]
        m[n1][n2] = True
        for i in xrange(n1-1, -1, -1):
            m[i][n2] = (s1[i] == s3[n2+i]) and m[i-1][n2]
        print m

if __name__ == '__main__':
    s = Solution()
    print s.isInterleave("abc", "ab", "aabbc")