class Solution {
public:
    string reverseString(string s) {
        string rev(s);
        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            rev[i] = s[j];
            rev[j] = s[i];
        }
        return rev;
    }
};