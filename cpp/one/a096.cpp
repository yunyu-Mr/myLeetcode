class Solution {
public:
    int numTrees(int n) {
        // Init
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        // DP
        for (int k = 3; k <= n; k++)
        {
            int h = k/2;    // half
            
            for (int i = 1; i <= h; i++)
                dp[k] += 2 * dp[i-1] * dp[k-i];
            // Odd length.
            if (k%2 == 1)
                dp[k] += dp[h] * dp[h];
        }
        
        return dp[n];
    }
};