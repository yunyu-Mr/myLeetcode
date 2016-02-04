/*
 *  Maximum Product Subarray
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int N = nums.size();
        if (N == 1)
        	return nums[0];

        //if there're at least 2 element, max result must greater than 0.
		int maxres = max(0, nums[0]),
			pos = max(1, nums[0]),
			neg = min(0, nums[0]);

		for (int i = 1; i < N; ++i) {
			if (nums[i] > 0) {
				pos = pos * nums[i];
				neg = neg * nums[i];
			}else if (nums[i] < 0){
				if (neg == 0) {	// not meet negative yet
					neg = pos * nums[i];
					pos = 1;
					continue;
				}else {	// pos must be positive; neg must be negative
					int tmp = pos;
					pos = neg * nums[i];
					neg = tmp * nums[i];
				}
			}else { // nums[i] == 0
				pos = 1;
				neg = 0;
				continue;
			}
			maxres = max(maxres, pos);
		}
		return maxres;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> nums = {1,0,-1,2,3,-5,-2};
	int prod = s.maxProduct(nums);
	cout<<prod<<endl;
	return 0;
}