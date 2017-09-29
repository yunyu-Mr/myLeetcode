class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> possible;
        backtracking(result, possible, candidates, 0, target);
        return result;
    }
    
    void backtracking(vector<vector<int>>& result, vector<int>& possible, vector<int>& candidates, int i, int target) {
        if (target < 0)
            return;
        if (target == 0) {
            result.push_back(possible);
            return;
        }
        if (i == candidates.size()) return;
        
        // use it!
        possible.push_back(candidates[i]);
        backtracking(result, possible, candidates, i, target - candidates[i]);
        possible.pop_back();
        // don't use, move next
        backtracking(result, possible, candidates, i + 1, target);
    }
};