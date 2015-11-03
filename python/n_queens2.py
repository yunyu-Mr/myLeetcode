class Solution(object):
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        self.total = 0
        x = []
        self.backtracking(0, n, x)
        return self.total

    def backtracking(self, t, n, x):
        """
        :param t: int
        :param n: int
        :param x: list
        """
        if t == n:
            # output t
            self.total += 1
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
    print s.totalNQueens(4)