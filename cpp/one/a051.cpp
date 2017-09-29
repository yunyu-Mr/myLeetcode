class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        string line(n, '.');
        vector<string> possible(n, line);
        
        backtracking(result, possible, 0);
        
        return result;
    }
    
    bool condition(vector<string>& possible, int i, int j) {
        int n = possible.size();
        for (int k = 0; k < i; k++) {
            // column
            if (possible[k][j] == 'Q')
                return false;
            // j + (i - k) ; j - (i - k);
            if (j+i-k < n && possible[k][j+i-k] == 'Q')
                return false;
            if (j-i+k >= 0 && possible[k][j-i+k] == 'Q')
                return false;
        }
        return true;
    }
    
    void backtracking(vector<vector<string>>& result, vector<string>& possible, int i) {
        int n = possible.size();
        if (i == n) {
            result.push_back(possible);
            return;
        }
        // Try each point of the i-th line.
        for (int j = 0; j < n; j++)
        {
            if (condition(possible, i, j))
            {
                possible[i][j] = 'Q';
                backtracking(result, possible, i+1);
                possible[i][j] = '.';
            }
        }
    }
};