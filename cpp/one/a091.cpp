class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0) return 0;
        
        // Decode set: ("1", "2", ..., "26")
        unordered_set<string> hs;
        for (int i = 1; i <= 26; i++)
            hs.insert(to_string(i));
        
        // Init
        vector<int> dp(n, 0);
        if (hs.find(s.substr(0, 1)) != hs.end()) dp[0]++;
        
        if (n >= 2) {
            if (hs.find(s.substr(1, 1)) != hs.end()) dp[1] += dp[0];
            if (hs.find(s.substr(0, 2)) != hs.end()) dp[1] += 1;
        }
        
        // DP
        for (int i = 2; i < n; i++)
        {
            if (hs.find(s.substr(i, 1)) != hs.end())   dp[i] += dp[i-1];
            if (hs.find(s.substr(i-1, 2)) != hs.end()) dp[i] += dp[i-2];
        }
        
        return dp[n-1];
    }
};