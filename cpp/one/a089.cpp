class Solution {
public:
    vector<int> grayCode(int n) {
        if (n < 1) return vector<int>{0};
        
        vector<int> code = {0, 1};
        for (int k = 1; k < n; k++) 
        {
            int d = 1 << k;
            for (int i = code.size()-1; i >= 0; i--)
                code.push_back (d + code[i]);
        }
        return code;
    }
};