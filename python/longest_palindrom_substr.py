

# class Solution(object):
# 	"""
# 	Longest palindrom substring
# 	Method 1: Expand from each char as center, time: O(n^2)
# 		1. Add '#', for example, 'aabbaa' => '#a#a#b#b#a#a#'
# 		2. Expand
# 		3. Split by '#', then join, return
# 	"""
# 	def longestPalindrom(self, s):
# 		ss = '#' + '#'.join(s) + '#'
# 		mx, ex, c = 0, 0, 0
# 		for i in xrange(len(ss)):
# 			ex = 0
# 			while (i-ex >= 0) and (i+ex <= len(ss)-1) and (ss[i-ex]==ss[i+ex]):
# 				if ex > mx:
# 					c = i
# 					mx = ex
# 				ex += 1
# 		res = ss[c-mx : c+mx+1]
# 		return ''.join(res.split('#'))
		
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        s1 = self.longestPalindromeOdd(s)
        s2 = self.longestPalindromeEven(s)
        if len(s1) > len(s2):
            return s1
        return s2

    def longestPalindromeOdd(self,s): # Odd length palindrom
        mx, ex, c = 0, 0, 0
        for i in xrange(len(s)):
            ex = 0
            while (i-ex >= 0) and (i+ex <= len(s)-1) and (s[i-ex]==s[i+ex]):
                if ex > mx:
                    c = i
                    mx = ex
                ex += 1
        return s[c-mx: c+mx+1]

    def longestPalindromeEven(self,s): # Even lenght palindrom
        mx, ex, c = 0, 0, 0
        for i in xrange(1,len(s)):
            ex = 0
            while (i-1-ex >= 0) and (i+ex <= len(s)-1) and (s[i-1-ex]==s[i+ex]):
                if ex > mx:
                    c = i
                    mx = ex
                ex += 1
        return s[c-mx-1: c+mx+1]

if __name__=='__main__':
    test = Solution()
    s = "aabbbaa"
    print test.longestPalindrome(s)
