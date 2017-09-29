class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash, dup;
        for (int i = 0; i < nums.size(); i++) {
        	if (hash.find(nums[i]) == hash.end())
        		hash[nums[i]] = i;
        	else
        		dup[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
        	int other = target - nums[i];

        	if (dup.find(other) != dup.end())
        		return vector<int>{i, dup[other]};

        	if (hash.find(other) != hash.end() && nums[i] != other)
        		return vector<int>{i, hash[other]};
        }
        return vector<int>{-1, -1};
    }
};