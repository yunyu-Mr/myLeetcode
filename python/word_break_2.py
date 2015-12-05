# Word Break 2

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

        self.allbreak = []
        if not mtx[len(s)][0]:
            print "Not breakable"
            return self.allbreak

        self.backtracking(s, wordDict, [], mtx, 0, len(s))
        return self.allbreak

    def backtracking(self, s, wordDict, abreak, mtx, start, wlen):
        """
        :param s:str
        :param wordDict: Set()
        :param abreak: List()
        :param mtx: List(List(str))
        :param start: int
        :param wlen: int
        """
        # l will not reach len(s)-start
        for l in xrange(1, len(s)-start):
            if s[start:start+l] in wordDict and mtx[wlen-l][start+l]:
                self.backtracking(s, wordDict, abreak+[s[start:start+l]], mtx, start+l, wlen-l)
        # When l equals to len(s)-start
        if s[start:] in wordDict:
            abreak.append(s[start:])
            self.allbreak.append(" ".join(abreak))

if __name__ == '__main__':
    s = Solution()
    print s.wordBreak("aaaaaaa", {"aaaa", "aa","a","and","dogs"})