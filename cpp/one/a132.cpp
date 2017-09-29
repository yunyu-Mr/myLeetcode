class Solution {
public:
    int minCut(string s) {
        int N = s.length();
        
        vector<int> dp(N+1, INT_MAX);
        dp[0] = dp[1] = 0;
        
        vector<vector<bool>> pal(N+1, vector<bool>(N+1, false));
        pal[0][0] = pal[1][1] = true;
        
        
        for (int k = 2; k <= N; k++) 
        {
            if (isPalindrome(s, pal, 0, k-1)) {
                dp[k] = 0;
                continue;
            } else {
                for (int i = 1; i < k; i++) { 
                    if (isPalindrome(s, pal, i, k-1))  // right substr, length = k - i
                        dp[k] = min(dp[k], dp[i] + 1);
                }
            }
        }
                
        return dp[N];
    }
    
    // Check palindrome by using memory.
    bool isPalindrome(const string& s, vector<vector<bool>> &pal, int i, int j) {
        if (i < j-1)
            pal[i][j] = pal[i+1][j-1] && s[i] == s[j];
        else
            pal[i][j] = s[i] == s[j];
        return pal[i][j];
    }
};