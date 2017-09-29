class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> possible;
        
        backtracking(result, possible, nums, 0);
        return result;
    }
    
    void backtracking(vector<vector<int>>& result, vector<int>& possible, vector<int>& nums, int i) {
        if (i == nums.size()) {
            result.push_back(possible);
            return;
        }
        backtracking(result, possible, nums, i+1);

        possible.push_back(nums[i]);
        backtracking(result, possible, nums, i+1);
        possible.pop_back();
    }
};