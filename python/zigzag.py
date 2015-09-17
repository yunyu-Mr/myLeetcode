class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        ziglist = ['' for x in range(numRows)]
        i, down = 0, True
        for c in s:
            ziglist[i] += c
            if i == numRows - 1:
                down = False
            elif i == 0:
                down = True
            if down == True:
                i += 1
            else:
                i -=1
        return ''.join(ziglist)



if __name__ == '__main__':
    s = Solution()
    print s.convert('abcdefg',3)