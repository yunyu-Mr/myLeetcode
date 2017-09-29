class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        
        string common = strs[0];
        int longest = common.length();
        
        for (int i = 1; i < strs.size(); i++){
            int j;
            for (j = 0; j < min<unsigned int>(longest, strs[i].length()); ++j)
                if (common[j] != strs[i][j]) break;
            longest = j;
            // cout << longest;
        }
        return longest >= 0 ? common.substr(0, longest) : "";
    }
};