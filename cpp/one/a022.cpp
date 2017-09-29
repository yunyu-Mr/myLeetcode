class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        backtracking(result, "(", n, 1, 0);
        
        return result;
    }
    
    void backtracking(vector<string>& result, string s, int n, int numLeft, int numRight) {
        if (numLeft == n) {
            if (numRight < n)
                s += string(n - numRight, ')');
            result.push_back(s);
            return;
        }
        
        if (numLeft > numRight) {
            backtracking(result, s + "(", n, numLeft +1, numRight);
            backtracking(result, s + ")", n, numLeft, numRight +1);
        } else if (numLeft == numRight)
            backtracking(result, s + "(", n, numLeft +1, numRight);
    }
};