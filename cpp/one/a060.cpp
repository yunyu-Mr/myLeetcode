class Solution {
public:
    string getPermutation(int n, int k) {
        long num = 1;
        vector<int> candidates(n, 0);
        for (int i = 1; i <= n; i++) {
            num *= i;
            candidates[i-1] = i;
        }
        
        string res = "";
        append(res, candidates, n, k-1, num);
        return res;
    }
    
    /**
     * Append recursively.
     * 
     * k = 0, 1, 2, ...
     * num = n!
     */
    void append(string& res, vector<int>& candidates, int n, int k, long num) {
        if (candidates.size() == 1) {
            res += ('0' + candidates[0]);
            return;
        }
        num = num / n;          // fact: (n-1)!
        int i = k / num;        // index
        res += ('0' + candidates[i]);  // append

        candidates.erase(candidates.begin() + i);
        append(res, candidates, n-1, k % num, num);
    }
};