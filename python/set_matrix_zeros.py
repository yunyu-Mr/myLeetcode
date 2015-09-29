__author__ = 'smtech'
"""
Set Matrix Zeros
"""
class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        m, n = 0, 0
        m = len(matrix)
        if m != 0:
            n = len(matrix[0])

        col = [1 for x in xrange(n)]
        # row = [1 for x in xrange(m)]
        row = 1

        for i in xrange(m):
            for j in xrange(n):
                if matrix[i][j] == 0:
                    # row[i], col[j] = 0, 0
                    row, col[j] = 0, 0
            if row == 0:
                for c in xrange(n):
                    matrix[i][c] = 0
                row = 1

        for c in xrange(n):
            if col[c] == 0:
                for i in xrange(m):
                    matrix[i][c] = 0

if __name__=='__main__':
    s = Solution()
    mtx = [
        [1,0]
    ]
    s.setZeroes(mtx)