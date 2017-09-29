class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        
        vector<int> ht(128, -1);  // Hash table (lookup array of ASCii char)
        int prev = 0,   // prev index
            cur = 1,    // current index
            maxlen = 1;
            
        ht[s[0]] = 0;   // Init
        
        while (cur < s.length()) {
            char c = s[cur];
            if (ht[c] >= prev) {
                prev = ht[c] + 1;  // already have, shrink
            }else {
                maxlen = max(maxlen, cur - prev + 1);
            }
            ht[c] = cur++;  // Update position
        }
        return maxlen;
    }
};