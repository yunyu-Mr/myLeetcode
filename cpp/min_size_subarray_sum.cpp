#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return minSubArrayLen(s, 0, nums.size()-1, nums);
    }

    int minSubArrayLen(int s, int l, int r, vector<int>& nums) {
    	if (l > r || s < 0)
    		return 0;

    	// while (r > l && s < nums[r]) r--;

    	// if (l == r && s != nums[r])
    	// 	return 0;
    	if (s == nums[l] || s == nums[r])
    		return 1;
    	if (s - nums[l] - nums[r] == 0) 
    		return 2;

    	int m = nums.size();

    	int a = minSubArrayLen(s - nums[l] - nums[r], l+1, r-1, nums);
    	if (a != 0)
    		m = min (a+2, m);

    	int b = minSubArrayLen(s - nums[l], l+1, r, nums);
    	if (b != 0)
    		m = min (b+1, m);

    	int c = minSubArrayLen(s - nums[r], l, r+1, nums);
    	if (c != 0) 
    		m = min (c+1, m);

    	int d = minSubArrayLen(s, l+1, r-1, nums);
    	if (d != 0)
    		m = min (d, m);

    	if (a == 0 && b == 0 && c == 0 && d == 0)
    		return 0;

    	return m;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	int s = 7;
	vector<int> nums = {2,3,1,2,4,3};
	cout << solution.minSubArrayLen(s, nums);
	return 0;
}