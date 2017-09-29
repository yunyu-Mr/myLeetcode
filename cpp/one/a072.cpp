class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(),
            n = word2.size();
        
        int dp[m+1][n+1];                   // DP table
        for (int j = 0; j < n+1; j++)       // Init row
            dp[0][j] = j;
        for (int i = 0; i < m+1; i++)       // Init col
            dp[i][0] = i;
        
        for (int i = 1; i < m+1; i++)           // i: substring length of word1
            for (int j = 1; j < n+1; j++) {     // j: substring length of word2
                if (word1[m-i] == word2[n-j]) {
                    dp[i][j] = dp[i-1][j-1];                    // substring
                } else {
                    dp[i][j] =               dp[i-1][j-1] + 1;  // replace
                    dp[i][j] = min (dp[i][j], dp[i][j-1] + 1);  // insert
                    dp[i][j] = min (dp[i][j], dp[i-1][j] + 1);  // delete
                }
            }
        return dp[m][n];
    }
};