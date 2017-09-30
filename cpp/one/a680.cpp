class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        for (; i < j; i++, j--) 
            if (s[i] != s[j])
                return isPalindrome(s.substr(i, j-i)) ||   // Skip right-most char
                       isPalindrome(s.substr(i+1, j-i));   // Skip left-most char
        
        return true;
    }
    
    bool isPalindrome(const string & s) {
        int i = 0, j = s.length() - 1;
        for (; i < j; i++, j--)
            if (s[i] != s[j])
                return false;
        return true;
    }
};