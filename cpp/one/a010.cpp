class Solution {
public:
    bool isMatch(string s, string p) {
        return backtrack(s, p, 0, 0);
    }
    
    bool backtrack(string& s, string& p, int i, int j) {
        int n = s.length(), m = p.length();
        
        if      (i == n && j == m) return true;
        else if (i > n || j >= m)  return false;
        
        if (j < m-1 && p[j+1] == '*') {            // '[a-z]*(...)' or '.*(...)'
            if (backtrack(s, p, i, j+2)) return true;   // match empty
            if (i < n && s[i] == p[j] || p[j] == '.')
                if (backtrack(s, p, i+1, j)) return true;   // match 1
        }
        else if (p[j] == '.' ||                                         // .(...)
                (p[j] >= 'a' && p[j] <= 'z' && i < n && s[i] == p[j]))  // [a-z](...)
        {
            if (backtrack(s, p, i+1, j+1)) return true;
        }
        else if (p[j] == '*') {                         // *(...)
            if (backtrack(s, p, i, j+1)) return true;   // match empty
            if (backtrack(s, p, i+1, j)) return true;   // match 1
        }
        return false;
    }
};