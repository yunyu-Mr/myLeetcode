# Word Break

class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: Set[str]
        :rtype: bool
        """
        # DP
        # Initial
        mtx = [[]]
        mtx.append([False for w in xrange(len(s))])
        for i in xrange(len(s)):
            if s[i] in wordDict:
                mtx[1][i] = True

        for wlen in xrange(2, len(s)+1):
            mtx.append([False for w in xrange(len(s)-wlen+1)])
            # i is the start point
            for i in xrange(len(s) - wlen+1):
                # if the substr is already in dict, continue
                if s[i:i+wlen] in wordDict:
                    mtx[wlen][i] = True
                    continue
                else:
                    # if the substr is not in dict, check the substrs of this substr
                    for j in xrange(1, wlen):
                        if mtx[j][i] and mtx[wlen-j][i+j]:
                            mtx[wlen][i] = True
                            break

        return mtx[len(s)][0]


if __name__ == '__main__':
    s = Solution()
    print s.wordBreak("leetcode", {"leet", "code"})