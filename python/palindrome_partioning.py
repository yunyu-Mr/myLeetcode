class Solution(object):
    def __init__(self):
        self.part_list = list()  # list of list
        self.possible = list()   # list

    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        self.backtracking(s, 0)
        return self.part_list

    def backtracking(self, s, slen):
        # If no more string can be cut, return.
        if slen >= len(s):
            self.part_list.append(self.possible[:])
            return

        # Cut k chars from the REST of the string.
        for k in range(len(s)-slen):
            # if it's not palindrome, don't add and drop it.
            if self.isPalindrome(s, slen, slen + k):
                self.possible.append(s[slen:slen+k+1])
                self.backtracking(s, slen + k + 1)
                self.possible.pop()
        return

    def isPalindrome(self, s, i, j):
        if j - i < 1:
            return True
        while i < j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True


if __name__ == "__main__":
    s = Solution()
    part_list = s.partition("aabb")
    for pl in part_list:
        print pl