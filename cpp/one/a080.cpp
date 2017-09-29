class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0,
            n = nums.size();
        if (n == 0) return 0;
        
        bool twice = false;
        for (int j = 1; j < n; j++)
        {
            // Wether it is allow.
            if (nums[i] != nums[j])       // not dup
            {
                nums[++i] = nums[j];
                twice = false;
            } else if (!twice) {        // first dup
                nums[++i] = nums[j];
                twice = true;
            }
        }
        return i + 1;
    }
};