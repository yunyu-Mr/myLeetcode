#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int n = nums.size();

    	// Find peek.
    	int p;
    	for (p = n-1; p > 0; p--)
    		if (nums[p] > nums[p-1]) break;

    	if (p == 0) {
    		reverse(nums.begin(), nums.end());
    		return;
    	}

    	for (int i = n - 1; i >= p; i--)
    		if (nums[i] > nums[p-1]) {
    			swap(nums[i], nums[p-1]);
    			break;
    		}
    	reverse(nums.begin() + p, nums.end());
    }
};

void printVec(const vector<int>& nums) {
	for (int n : nums)
		cout << n << " ";
	cout << endl;
}

int main(int argc, char const *argv[])
{
	Solution s;

	vector<int> nums = {1,2,3};
	for (int i = 0; i < 6; i++) {
		s.nextPermutation(nums);
		printVec(nums);
	}
	return 0;
}