class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        self.cheeseboards = list()
        x = []
        self.backtracking(0, n, x)
        return self.cheeseboards

    def backtracking(self, t, n, x):
        """
        :param t: int
        :param n: int
        :param x: list
        """
        if t == n:
            # output t
            board = []
            for p in x:
                board.append("".join(['.' for l in xrange(p)]) + "Q" + "".join(['.' for r in xrange(len(x)-1-p)]) )
            self.cheeseboards.append(board)
        else:
            for i in xrange(n):
                # choose a position and place
                if self.place(i, x):
                    self.backtracking(t+1, n, x +[i])

    def place(self, k, x):
        """
        :param k: int
        :param x: list
        :return:  bool
        """
        for i in xrange(len(x)):
            if (k == x[i]) or k == (len(x) -i +x[i]) or (k == (x[i] -(len(x)-i))):
                return False
        return True

if __name__ == "__main__":
    s = Solution()
    print s.solveNQueens(4)