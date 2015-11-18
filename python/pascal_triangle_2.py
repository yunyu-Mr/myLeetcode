# Pascal' Triangle II

class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex == 0:
            return [1]
        if rowIndex == 1:
            return [1,1]
        # Init
        row1 = [0 for x in range(rowIndex+1)]
        row1[0] = 1
        row2 = [0 for x in range(rowIndex+1)]
        row2[0], row2[1] = 1, 1
        # rowc is the current row
        # rowp is the previous row
        for k in xrange(2, rowIndex+1):
            # Get turn
            if k % 2 == 0:
                rowc = row1
                rowp = row2
            else:
                rowc = row2
                rowp = row1
            # caculate i=1 to k-1, as rowc[0] = 1, rowc[k] = 1
            for i in xrange(k-1):
                rowc[i+1] = rowp[i] + rowp[i+1]
            rowc[k] = 1
        return rowc
