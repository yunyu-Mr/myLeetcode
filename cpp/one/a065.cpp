class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        int i = 0, j = n-1;
        // Trim space
        for (; i < n; i++)
            if (s[i] != ' ') break;
        for (; j >= 0; j--)
            if (s[j] != ' ') break;
        if (i > j) return false;
        // DFA
        int st = 0;  // state
        for (int k = i; k <= j; k++)
        {
            char c = s[k];
            if (c >= '0' && c <= '9') {  // digit
                if      (st == 2 || st == 4 || st == 7) continue;
                else if (st == 0 || st == 1) st = 2;
                else if (st == 3)            st = 4;
                else if (st == 5 || st == 6) st = 7;
                else return false;
            }
            else if (c == '.') {        // dot
                if      (st == 0 || st == 1) st = 3;
                else if (st == 2)            st = 4;
                else return false;
            }
            else if (c == 'e') {        // exp
                if (st == 2 || st == 4) st = 5;
                else return false;
            }
            else if (c == '+' || c == '-') { // sign
                if      (st == 0) st = 1;
                else if (st == 5) st = 6;
                else return false;
            } else
                return false;           // other
        }
        if (st == 2 || st == 4 || st == 7) // accept states
            return true;
        return false;
    }
};