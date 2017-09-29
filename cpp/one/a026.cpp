class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int i = 1;
        for (int j = i; j < nums.size(); j++)
            if (nums[j] != nums[j-1]) {
                nums[i++] = nums[j];
            }
        return i;
    }
};