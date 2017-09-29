class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int k = 0; k < n-1; k++) 
        {
            string tmp = "";
            char d = s[0];
            int cnt = 1;
            
            for (int i = 1; i < s.length(); i++) {
                if (s[i] == s[i-1]) cnt++;
                else {
                    tmp += to_string(cnt) + d;
                    d = s[i];
                    cnt = 1;
                }
            }
            s = tmp + to_string(cnt) + d;
        }
        return s;
    }
};