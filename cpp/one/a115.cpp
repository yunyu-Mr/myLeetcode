class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(),
            m = t.length();
        
        if (m > n) return 0;
        
        vector<vector<int>> tb(m+1, vector<int>(n+1, 0));
        for (int j = 0; j <= n; j++)
            tb[m][j] = 1;
        
        for (int i = m-1; i >= 0; i--)
            for (int j = n-1; j >= 0; j--)
                if (t[i] == s[j])
                    tb[i][j] = tb[i][j+1] + tb[i+1][j+1];
                else
                    tb[i][j] = tb[i][j+1];
        
        return tb[0][0];
    }
};