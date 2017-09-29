class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int fartest = 0;        // fartest position.
        vector<int> steps(n, n);  // the minimum steps to the i-th num.
        steps[0] = 0;       // init
        
        for (int i = 0; i < n-1; i++) {
            if (i + nums[i] > fartest) {
                // 若超出最远位置，则step增加1.
                for (int j = fartest + 1; j < n && j <= i + nums[i]; j++)
                    steps[j] = 1 + steps[i];
                fartest = i + nums[i];
            }
        }
        return steps[n-1];
    }
};