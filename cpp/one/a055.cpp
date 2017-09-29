class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return true;
        
        int fartest = 0;
        for (int i = 0; i < n-1; i++) 
        {
            // can't go ahead any more.
            // iff reach the point that is 0.
            if (i == fartest && nums[i] == 0)
                return false;
            // reach farther
            if (i + nums[i] > fartest)
                fartest = i + nums[i];
        }
        return fartest >= n-1;
    }
};