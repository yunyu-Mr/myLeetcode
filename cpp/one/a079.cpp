#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (m == 0) return false;
        int n = board[0].size();
        if (n == 0) return false;
        
        vector<vector<bool>> chose(m, vector<bool>(n, 0));  // boolean matrix
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (backtrack(board, chose, word, i, j, 0))
                    return true;
        return false;
    }
    
    bool backtrack(vector<vector<char>>& board, vector<vector<bool>>& chose, const string& word, int i, int j, int d)
    {
        if (board[i][j] != word[d])
            return false;
        else if (d == word.length() -1)
            return true;

        chose[i][j] = 1;

        if (i > 0 && !chose[i-1][j])
            if (backtrack(board, chose, word, i-1, j, d+1)) return true;
        if (j > 0 && !chose[i][j-1])
            if (backtrack(board, chose, word, i, j-1, d+1)) return true;
        if (i < board.size() -1 && !chose[i+1][j])
            if (backtrack(board, chose, word, i+1, j, d+1)) return true;
        if (j < board[0].size() -1 && !chose[i][j+1])
            if (backtrack(board, chose, word, i, j+1, d+1)) return true;

        chose[i][j] = 0;
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<char>> board = {{'a', 'a'}};
    string word = "aa";
    s.exist(board, word);
    return 0;
}