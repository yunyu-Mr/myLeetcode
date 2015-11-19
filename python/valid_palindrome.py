class Solution(object):
    def isAlphanumeric(self, c):
        asc = ord(c)
        if asc < ord('0') or (asc > ord('9') and asc < ord('a')) or asc > ord('z'):
            return False
        return True

    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s) == 0:
            return True

        sl = s.lower()
        i, j = 0, len(s)-1
        while i < j:
            if not self.isAlphanumeric(sl[i]):
                i += 1
                continue
            if not self.isAlphanumeric(sl[j]):
                j -= 1
                continue
            if sl[i] == sl[j]:
                i += 1
                j -= 1
            else:
                return False
        return True

if __name__ == '__main__':
    s = Solution()
    print s.isPalindrome('1a1')