"""
Spiral Matrix

Using recursive method:
  1. First outter round
  2. Then inner sub-matrix
"""
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        m = len(matrix)
        if m == 0:  # in case empty: [  ]
            return []
        n = len(matrix[0])
        if n == 0: # in case empty: [ [],[],[],[],..., [] ]
            return []
        if m==1:  # single row
            return matrix[0]
        if n==1:  # single col
            return [x[0] for x in matrix]
        
        res = list()
        for j in xrange(n-1):
            res.append(matrix[0][j])
        print res

        for i in xrange(m-1):
            res.append(matrix[i][n-1])
        print res

        for j in xrange(n-1, 0, -1):
            res.append(matrix[m-1][j])
        print res

        for i in xrange(m-1, 0, -1):
            res.append(matrix[i][0])
        print res

        inner = list()
        for row in matrix[1:m-1]:
            inner.append(row[1:n-1])
        print 'inner',inner
        return res + self.spiralOrder(inner[:]) # recursive