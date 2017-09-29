class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1) return 1;
        
        int res = 0;
        // DP table
        int tb[m][n];  // num of unique path
        for (int i = 0; i < m-1; i++) tb[i][n-1] = 1;
        for (int j = 0; j < n-1; j++) tb[m-1][j] = 1;
        // DP
        for (int i = m-2; i >=0; i--)
            for (int j = n-2; j >= 0; j--)
                tb[i][j] = tb[i+1][j] + tb[i][j+1];
                
        return tb[0][0];
    }
};