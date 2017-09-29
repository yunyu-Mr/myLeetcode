class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board, 0);
    }
    
    bool backtracking(vector<vector<char>>& board, int d) {
        if (d == 81) return true;
        
        // Convert to 2D index.
        int i = d / 9;
        int j = d - 9 * i;
        if (board[i][j] != '.')
            return backtracking(board, d+1);
        
        // Get candidate char
        const auto& candi = candidate(board, i, j);
        if (candi.size() == 0) return false;
        
        // Try each char.
        for (char c : candi) {
            board[i][j] = c;  // to char
            if (backtracking(board, d+1)) return true;
            // if fail, try another char.
        }
        // Important! If fail, recover for trying another char.
        board[i][j] = '.';
        return false;
    }
    
    vector<char> candidate(vector<vector<char>>& board, int i, int j) {
        unordered_map<char, int> ht;    // hash table for tracking used chars.
        vector<char> res;               // store candidate chars.
        for (int k = 0; k < 9; k++) {
            ++ht[board[i][k]];  // row
            ++ht[board[k][j]];  // col
        }
        for (int s1 = 3*(i/3), k = 0; k < 3; k++)
            for (int s2 = 3*(j/3), l = 0; l < 3; l++)
                ++ht[board[s1+k][s2+l]];    // sub board
        // which are not been used?
        for (char c = '1'; c <= '9'; c++)
            if (ht.find(c) == ht.end())
                res.push_back(c);
        return res;
    }
};