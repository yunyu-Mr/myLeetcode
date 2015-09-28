# -*- coding: utf-8 -*-
"""
最长公共子序列
"""
def longest_common(s1, s2):
    """
    : type s1, s2: string
    : rtype length 
    """
    m = [[0 for col in xrange(len(s2)+1)] for row in xrange(len(s1)+1)]
    longest = 0
    for i in xrange(1, 1+len(s1)):
        for j in xrange(1, 1+len(s2)):
            print s1[-1], s2[-1]
            if s1[:i][-1] == s2[:j][-1]:
                m[i][j] = m[i-1][j-1] + 1
            else:
                m[i][j] = max(m[i-1][j], m[i][j-1])
                longest = max(longest, m[i][j])
    for line in m:
        print line
    return longest


if __name__ == '__main__':
    s1 = 'abcdabcd'
    s2 = 'eabceefd'
    print longest_common(s1, s2)