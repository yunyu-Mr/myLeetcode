class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> prevPos;
        
        for (int i = 0; i < nums.size(); i++)
            if (prevPos.count(nums[i]) > 0 && prevPos[nums[i]] + k >= i)
                return true;
            else
                prevPos[nums[i]] = i;
        return false;
    }
};