class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        n1, n2, n3 = len(s1), len(s2), len(s3)
        if n3 != n1+n2:
            return False
        if n1 == 0 and n2 == 0 and n3 == 0:
            return True
        # --------   Init matrix --------
        m = [[False for col in xrange(1+n2)] for row in xrange(1+n1)]
        m[n1][n2] = True
        # Choose s1 and don't choose s2
        for i in xrange(n1-1, -1, -1):
            m[i][n2] = (s1[i] == s3[n2+i]) and m[i+1][n2]
        # Choose s2 and don't choose s1
        for j in xrange(n2-1, -1, -1):
            m[n1][j] = (s2[j] == s3[n1+j]) and m[n1][j+1]

        # Recursive Solution:
        # For example, s1 ='abc', s2 ='bcf', s3 ='abbccf'. As 'a' is the first,
        # we should only check isInterleaving('bc', bcf, 'bbccf').
        # Clearly, such a recursion is overlapping, so we can use dynamic programming.

        # Iteration
        for i in xrange(n1-1, -1, -1):
            for j in xrange(n2-1, -1, -1):
                ch = s3[i+j] # Remain value
                # print "s3:%s, s1:%s, s2:%s" %(ch, s1[i], s2[j])
                m[i][j] = (m[i+1][j] and s1[i] == ch) or (m[i][j+1] and s2[j] == ch)
        # print m
        return m[0][0]

if __name__ == '__main__':
    s = Solution()
    print s.isInterleave("aabca", "bbdcf", "ababbcdcfa")