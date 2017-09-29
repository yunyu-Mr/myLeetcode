class Solution {
public:
    int totalNQueens(int n) {
        int total = 0;
        string line(n, '.');
        vector<string> possible(n, line);
        
        // The solutions are symmetrical.
        for (int i = 0; i < n/2; i++) {
            possible[0][i] = 'Q';
            backtracking(total, possible, 1);
            possible[0][i] = '.';
        }
        total *= 2;
        if (n%2 == 1) {
            possible[0][n/2] = 'Q';
            backtracking(total, possible, 1);
        }
        
        return total;
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
    
    void backtracking(int & total, vector<string>& possible, int i) {
        int n = possible.size();
        if (i == n) {
            total++;
            return;
        }
        // Try each point of the i-th line.
        for (int j = 0; j < n; j++)
        {
            if (condition(possible, i, j))
            {
                possible[i][j] = 'Q';
                backtracking(total, possible, i+1);
                possible[i][j] = '.';
            }
        }
    }
};