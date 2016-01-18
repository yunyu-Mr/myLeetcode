/*
 *  Find Minimum in Rotated Sorted Array
 *  
 *  Find the break point
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
    	if (nums.size() <= 0)
    		return 0;
    	if (nums.size() == 1)
    		return nums[0];

    	return findMin(nums, 0, nums.size() -1 );
    }

    int findMin(vector<int>& nums, int i, int j) {
    	// Leave only 2 elements:
    	if (j - i == 1) {
    		if (nums[i] > nums[j])
    			return nums[j];
    		else
    			return nums[0];
    	}

		int m = (i + j) / 2;
		// Compare first and the mid
		if (nums[i] > nums[m]) {
			// First larger than mid, break point must in the left part;
			return findMin(nums, i, m);
		}
		// Otherwise, the left part is ordered. Break point must in right part.
        return findMin(nums, m, j);
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> nums = {0,1,2,3,4};
	cout<<s.findMin(nums)<<endl;
	return 0;
}