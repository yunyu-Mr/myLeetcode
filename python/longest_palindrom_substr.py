"""
Manachar's Algorithm
"""
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        cen, mx = 0, 0
        sn = '#' + '#'.join(s) + '#'
        p = [0 for x in range(len(sn))]
        for i in xrange(len(sn)):
            if i >= mx:
                pass
            else:
                j = cen * 2 - i  # cen = (i + j) / 2
                p[i] = min(mx-i, p[j])  # limit p[i] not exceed mx
            while  (i+p[i]+1 < len(sn)) and (i-p[i]-1 >= 0) and (sn[i+p[i]+1] == sn[i-p[i]-1]): #expand
                p[i] += 1
            if p[i] >= mx - cen:
                cen = i
                mx = cen + p[i]
        return ''.join(sn[2*cen - mx : mx].split('#'))

if __name__=='__main__':
    test = Solution()
    s = "aabbaa"
    print test.longestPalindrome(s)
