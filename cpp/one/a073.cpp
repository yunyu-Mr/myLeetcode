class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        
        unordered_set<int> row, col;    // hash table.
        
        // Find those rows and columns that should be zero.
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
        // Each row.
        for (int i = 0; i < m; i++) {
            if (row.find(i) == row.end()) continue;
            for (int j = 0; j < n; j++) matrix[i][j] = 0;
        }
        // Each col.
        for (int j = 0; j < n; j++) {
            if (col.find(j) == col.end()) continue;
            for (int i = 0; i < m; i++) matrix[i][j] = 0;
        }
    }
};