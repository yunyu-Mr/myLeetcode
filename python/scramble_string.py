"""
Scramble String
"""
class Solution(object):
    """docstring for Solution"""
    def isScramble(setf, s1, s2):
        if len(s1) != len(s2):
            return False
        n = len(s1)
        if n == 0:
            return False
        if n == 1:
            return s1 == s2
        # Memozie matrix
        m = list()
        m.append([])
        for k in xrange(1, n+1):
            m.append([])
            for i in xrange(n-k+1):
                m[k].append([])
                for j in xrange(n-k+1):
                    m[k][i].append([])
                    m[k][i][j] = False
        for i in xrange(n):
            for j in xrange(n):
                if s1[i] == s2[j]:
                    m[1][i][j] = True
        # for x in m:
        #     print x
        for k in xrange(2, n+1):
            for i in xrange(n-k+1):
                for j in xrange(n-k+1):
                    for l in xrange(1, k):
                        m[k][i][j] = m[k][i][j] or \
                                     (m[l][i][j] and m[k-l][i+l][j+l]) or \
                                     (m[l][i][j+k-l] and m[k-l][i+l][j])
        # for x in m:
        #     print x
        return m[n][0][0]

if __name__=='__main__':
    s = Solution()
    print s.isScramble('great','grtea')

