class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        
        int n = s1.length(),
            m = s2.length();
        if (n > m)
            return false;
        
        // Init frequency table.
        for (int i = 0; i < n; i++) {
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        if (freq1 == freq2)
            return true;
        
        // Sliding window update frequency table.
        for (int i = n; i < m; i++) 
        {
            freq2[s2[i]   - 'a']++;  // add next char
            freq2[s2[i-n] - 'a']--;  // remove the first char
            if (freq1 == freq2)
                return true;
        }
        return false;
    }
};