class Solution {
public:
    /**
     * 重叠子问题：将一个str分裂成两份，分别检查。
     *
     * 采用DP，bottom up，子串的长度从1到N。
     */
    bool wordBreak(string s, vector<string>& wordDict) {
        int N = s.length();
        if (N == 0) return false;
        
        unordered_set<string> wordSet;  // Words Dict
        for (auto word : wordDict)
            wordSet.insert(word);
        
        vector<vector<bool>> dp(N+1, vector<bool>(N, false));  // DP table
        
        // Init: for substr length = 1
        for (int i = 0; i < N; i++)
            if (wordSet.count(s.substr(i,1)))
                dp[1][i] = true;
        
        for (int k = 2; k <= N; k++)  // k = 2, 3, ..., N
            for (int i = 0; i <= N-k; i++)  // i: start point
                if (wordSet.count(s.substr(i,k)))
                    dp[k][i] = true;
                else
                {   // search sub-problems
                    for (int l = 1; l < k; l++)
                        if (dp[l][i] && dp[k-l][i+l]) {
                            dp[k][i] = true;
                            break;
                        }
                }

        return dp[N][0];
    }

    // 解法2
    bool wordBreak(string s, vector<string>& wordDict) {
        int N = s.length();
        
        unordered_set<string> wordSet;  // Words Dict
        for (auto word : wordDict)
            wordSet.insert(word);
        
        vector<bool> dp(N+1, false);
        dp[0] = true;
        
        for (int i = 1; i <= N; i++)
            for (int j = 0; j < i; j++)
                if (dp[j])
                    if (wordSet.count(s.substr(j,i-j))) {
                        dp[i] = true;
                        break;
                    }

        return dp[N];
    }
};