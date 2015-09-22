import re

"""
Decode Ways
"""
class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0:
            return 0
        # First few codes should not be '0', if, it is invalid!
        if s[0] == '0':
            return 0
        # Should not contain '00...', invalid!!
        ss = [x for x in s.split('00')]
        if '' in ss:
            return 0
        # '10', '20' can be recognized as a single code
        ss = re.split('10|20',s)
        print ss
        # Should not contain '30', '40', ..., '90', invalid!!
        if '0' in ''.join(ss):
            return 0
        # The remaining code is pure non-zero
        n = 1
        for si in ss:
            n = n * self.numDecodingsEach(si)
        return n
        
        
    def numDecodingsEach(self, s):
        if len(s) < 3:
            if s == '':
                return 1
            if int(s) > 26:
                return 1
            return max(1, len(s))
        d = [1, 2]
        if int(s[0:2]) > 26:
            d[1] = 1
        for i in xrange(2, len(s)):
            d.append(0)
            if int( s[i-1:i+1] ) > 26:
                    d[i] = d[i-1]
            else:
                d[i] = d[i-1] + d[i-2]
        return d[-1]

if __name__ == '__main__':
    s = Solution()
    print s.numDecodings('100212485')