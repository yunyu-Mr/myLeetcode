class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = list()  # use to push string char's index
        max_len = 0
        for i in xrange(len(s)):
            if stack and s[i] == ')':
                if s[stack[-1]] == '(':  # stack[-1] is index
                    stack.pop()
                else:
                    stack.append(i)
                # init, if stack is empty, low is -1
                low = -1
                # if stack is not empty, low is stack top
                if stack:
                    low = stack[-1]
                # caculate max length by using index
                max_len = max(max_len, i - low)
            else:
                stack.append(i)
        return max_len

if __name__ == '__main__':
    s = Solution()
    print s.longestValidParentheses('()')