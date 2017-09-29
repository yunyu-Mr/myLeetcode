class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>& tb = obstacleGrid;
        int m = tb.size(),
            n = tb[0].size();
        // Init
        if (tb[m-1][n-1] == 1) return 0;
        else tb[m-1][n-1] = 1;
        
        for (int i = m-2; i >= 0; i--) {    // right most column
            if (tb[i][n-1] == 1) 
                tb[i][n-1] = 0;
            else
                tb[i][n-1] = tb[i+1][n-1];
        }
        for (int j = n-2; j >= 0; j--) {    // bottom row
            if (tb[m-1][j] == 1)
                tb[m-1][j] = 0;
            else
                tb[m-1][j] = tb[m-1][j+1];
        }
        // DP: from bottom to top, right to left.
        for (int i = m-2; i >= 0; i--)
            for (int j = n-2; j >= 0; j--) {
                if (tb[i][j] == 1)  // obstacle
                    tb[i][j] = 0;
                else
                    tb[i][j] = tb[i+1][j] + tb[i][j+1];   // update
            }
        return tb[0][0];
    }
};