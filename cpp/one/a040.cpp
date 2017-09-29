class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> possible;
        
        sort(candidates.begin(), candidates.end());
        
        backtracking(result, possible, candidates, 0, target);
        
        return result;
    }
    
    void backtracking(vector<vector<int>>& result, vector<int>& possible, vector<int>& candidates, int i, int target) {
        if (target < 0) return;
        if (target == 0) {
            result.push_back(possible);
            return;
        }
        if (i == candidates.size()) return;
        
        int j;
        for (j = i; j+1 < candidates.size() && candidates[j] == candidates[j+1]; j++);
        
        backtracking(result, possible, candidates, j+1, target);
        for (int k = i; k <= j; k++) {
            possible.push_back(candidates[k]);
            target -= candidates[k];
            backtracking(result, possible, candidates, j+1, target);
        }
        // recover.
        for (int k = i; k <= j; k++)
            possible.pop_back();
    }
};