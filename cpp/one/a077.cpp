class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> possible;

        backtracking(result, possible, n, k, 0);
        return result;
    }
    
    void backtracking(vector<vector<int>>& result, vector<int>& possible, int n, int k, int i) {
        if (possible.size() == k) {
            result.push_back(possible);
            return;
        }
        if (possible.size() + n -i < k) return;
        
        possible.push_back(i+1);
        backtracking(result, possible, n, k, i+1);  // choose i
        possible.pop_back();
        
        backtracking(result, possible, n, k, i+1);  // without i
    }
};