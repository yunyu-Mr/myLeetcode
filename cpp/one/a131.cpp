class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> results;
        vector<string> path;
        
        partition(s, 0, path, results);
        
        return results;
    }
    
    // Backtracking
    void partition(const string& s, int i, vector<string> &path, vector<vector<string>> &results) 
    {
        int N = s.length();
        if (i == N) {
            results.push_back(path);
            return;
        }
        
        for (int j = i+1; j <= N; j++)      // i: start point, j: partition point
        {
            const string& sub = s.substr(i, j-i);
            if (isPalindrome(sub))      // constrain
            {
                path.push_back(sub);
                partition(s, j, path, results);
                path.pop_back();
            }
        }
    }
    
    // Constrain
    bool isPalindrome(const string& s)
    {
        for (int i = 0, j = s.length() - 1; i < j; i++, j--)
            if (s[i] != s[j])
                return false;
        return true;
    }
};