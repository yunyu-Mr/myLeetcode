class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n, 0);
        sums[0] = nums[0];
        
        int mx = sums[0];
        for (int i = 1; i < n; i++) {
            sums[i] = max (sums[i-1] + nums[i], nums[i]);
            mx = max (mx, sums[i]);
        }
        return mx;
    }
};