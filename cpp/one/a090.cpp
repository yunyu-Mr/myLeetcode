class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> possible;
        //
        sort(nums.begin(), nums.end());
        //
        backtrack(result, possible, nums, 0);
        return result;
    }
    
    void backtrack(vector<vector<int>>& result, vector<int>& possible, vector<int>& nums, int i) {
        if (i == nums.size()) {
            result.push_back(possible);
            return;
        }
        
        int j = i+1;
        for (; j < nums.size(); j++)
            if (nums[j] != nums[i])
                break;
        // Choose 0 nums[i].
        backtrack(result, possible, nums, j);
        // Choose 1,2,...,(j-i) nums[i].
        for (int k = i; k < j; k++) {
            possible.push_back(nums[k]);
            backtrack(result, possible, nums, j);
        }
        // Recovery.
        for (int k = i; k < j; k++)
            possible.pop_back();
    }
};