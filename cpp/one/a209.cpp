class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int N = nums.size();
        if (N == 0) return 0;
        
        int win = nums[0];
        int len = N+1;
        int i = 0, j = 0;
        while (i < N && j < N) {
            if (win < s) {
                j++;
                if (j < N) win += nums[j];   // expand
            } else {
                len = min(len, j-i+1);
                win -= nums[i];           // shrink
                i++;
            }
            if (i > j) j = i;
        }
        return len == N+1 ? 0 : len;
    }
};