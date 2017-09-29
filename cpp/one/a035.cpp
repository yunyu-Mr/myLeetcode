class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        
        int i = 0,
            j = nums.size() - 1;

        while (i < j) {
            int m = (i + j) / 2;
            if      (target < nums[m]) j = m;
            else if (target > nums[m]) i = m + 1;
            else                       return m;
        }
        
        if (target > nums[i])
            return i + 1;
        return i;
    }
};