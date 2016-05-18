NONE = 0
UP = 1
DOWN = 2
LEFT = 3
RIGHT = 4

class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        self.board = board
        self.word = word
        self.m = len(board)
        if self.m == 0:
            return False
        self.n = len(board[0])
        if self.n == 0:
            return False
        self.l = len(word)
        if self.l == 0:
            return False
        
        # Visited flag matrix.
        self.visited = [[False for x in xrange(self.n)] for y in xrange(self.m)]
                
        # The first char.
        h = self.word[0]
        # Backtracking.
        for i in xrange(self.m):
            for j in xrange(self.n):
                if h == self.board[i][j]:
                    # Begin to track the word.
                    if self.exist_s (i, j, 0, NONE):
                        return True
        return False
                    
    def exist_s(self, i, j, k, direct):
        if self.visited[i][j]:
            return False
        # print self.word[k], self.board[i][j]
        if self.word[k] != self.board[i][j]:
            return False
        
        # Ok! Visit it and check next.
        self.visited[i][j] = True
        k += 1
        
        # Whole word has been checked, return True.
        if k >= self.l:
            return True
            
        # Check four direction.
        if direct != UP and i < self.m - 1:
            if self.exist_s (i+1, j, k, DOWN):
                return True
        if direct != DOWN and i > 0:
            if self.exist_s (i-1, j, k, UP):
                return True
        if direct != LEFT and j < self.n - 1:
            if self.exist_s (i, j+1, k, RIGHT):
                return True
        if direct != RIGHT and j > 0:
            if self.exist_s (i, j-1, k, LEFT):
                return True      
        
        # At last, remember to release visited flag.
        self.visited[i][j] = False
        return False
        
if __name__ == '__main__':
    s = Solution()
    board = ["ABCE","SFCS","ADEE"]
    word = "ABCCED"
    # print s.exist (board, word)
    
    print s.exist (["a"], "a")
    
    print s.exist (["ab", "cd"], "cdba")
    
    # print s.exist (["aaaa","aaaa","aaaa"], "aaaaaaaaaaaaa")