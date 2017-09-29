class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Check a positive and let it to the exact position.
            while (nums[i] > 0 && nums[i] != i+1) {
                int idx = nums[i] - 1;
                if (idx < n && nums[i] != nums[idx])
                    swap(nums[idx], nums[i]);
                else break;
            }
        }
        for (int i = 0; i < n; i++)
            if (nums[i] != i+1)
                return i+1;
        return n + 1;
    }
};