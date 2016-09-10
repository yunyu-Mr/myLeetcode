class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        s_num = []  # stack for repeat number
        s_dec = []  # stack for decoded string
        num_str = ''    # read number string
        dec_str = ''    # read character string
        for i in xrange(len(s)):
            c = s[i]
            if c >= 'a' and c <= 'z':
                dec_str += c
            elif c >= '0' and c <= '9':
                num_str += c
            elif c == '[':
                s_num.append(int(num_str))  # push in stack
                num_str = ''    # clear num_str
                s_dec.append(dec_str)
                dec_str = ''    # clear dec_str
            elif c == ']':
                num = s_num.pop()
                dec = s_dec.pop()
                dec_str = dec + ''.join([dec_str for i in xrange(num)]) # add repeat string.
        return dec_str


if __name__ == '__main__':
    s1 = '3[a2[c]]'
    s2 = '2[abc]3[cd]ef'
    solution = Solution()
    print('%s -> %s' % (s1, solution.decodeString(s1)))
    print('%s -> %s' % (s2, solution.decodeString(s2)))

