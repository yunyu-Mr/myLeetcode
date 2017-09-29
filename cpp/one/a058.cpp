class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        
        // Find the first non-space char.
        int i = n-1;
        while (i >= 0 && s[i] == ' ') i--;
        if (i < 0) return 0;
        
        // Find the next space.
        int j = i;
        while (j >= 0 && s[j] != ' ') j--;
        
        return i - j;
    }
};