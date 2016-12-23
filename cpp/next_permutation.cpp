#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Find peek.
        int p;
        for (p = nums.size()-1; p > 0; p--)
            if (nums[p] > nums[p-1]) break;
        if (p == 0) {	// restart
            std::reverse(nums.begin(), nums.end());
            return;
        }
        
        // Find a num from peek right that mearly larger than peek's left.
        int j = p - 1;
        for (int i = nums.size()-1; i > j; i--)
            if (nums[i] > nums[j]) { // swap
            	swap(nums[i], nums[j]);
                break;
            }

        // Reverse
        std::reverse (nums.begin() + p, nums.end());
    }
};

void printVec(const std::vector<int>& v) {
	for (int val: v)
		cout << val << " ";
	cout << endl;
}

int main(int argc, char const *argv[])
{
	vector<int> nums = {1, 2, 3, 4};
	Solution s;
	for (int i = 0; i < 24; i++) {
		s.nextPermutation(nums);
		printVec(nums);
	}
	return 0;
}