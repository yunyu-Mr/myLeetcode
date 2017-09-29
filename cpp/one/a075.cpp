class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for (int k : {0, 1})
        {
            int j = i +1;
            while (i < n && j < n) {
                while (nums[i] == k) i++;           // Find not a 'k'
                
                if (i >= j) j = i+1;                // ensure i < j
                while (j < n && nums[j] != k) j++;  // Find a 'k'

                if (j < n)
                    swap(nums[i++], nums[j++]);     // swap and move next.
            }
        }
    }
};