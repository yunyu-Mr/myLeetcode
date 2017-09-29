class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        
        backtrack(s, res, "", 0, 1);
        return res;
    }
    
    // Check whether it is a valid str num.
    bool isValid(const string &s, int k) {
        if      (s.length() == 0)      return false;
        else if (k > 1 && s[0] == '0') return false;
        return true;
    }
    
    void backtrack(const string &s, vector<string> &res, string possible, int p, int d) {
        if (d == 4) {
            int rs = s.length() - p; // rest length
            if (rs > 3) return;      // must less than 3
            
            const string& sub = s.substr(p, rs);
            if (isValid(sub, rs) && stoi(sub) < 256)
                res.push_back (possible + sub);
            return;
        }
        
        for (int k = 1; k <= 3; k++)
            if (p + k <= s.length()) {  // within string range
                const string& sub = s.substr(p, k);
                if (isValid(sub, k) && stoi(sub) < 256)
                    backtrack(s, res, possible + sub + ".", p+k, d+1);
            }
    }
};