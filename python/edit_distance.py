__author__ = 'smtech'
class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        m = [ [0 for col in xrange(len(word2)+1)] for row in xrange(len(word1)+1)]
        for j in xrange(len(word2)+1):
            m[0][j] = j
        for i in xrange(len(word1)+1):
            m[i][0] = i

        for i in xrange(1, 1+len(word1)):
            for j in xrange(1, 1+len(word2)):
                if word1[:i][-1] != word2[:j][-1]:
                    # 1.Replace  2.Word1 delete 3.Word2 delete
                    m[i][j] = min(m[i-1][j-1] + 1, m[i-1][j]+1, m[i][j-1]+1)
                else:
                    m[i][j] = m[i-1][j-1]
        for line in m:
            print line
        return m[-1][-1]

if __name__=='__main__':
    s = Solution()
    print s.minDistance("a","ab")