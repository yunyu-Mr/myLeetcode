#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int front = 0, pos = 0;
        int n = nums.size();
        
        // Find the first non-zero positoin.
        while (pos < n && nums[pos] == 0) pos++;
        
        while (pos < n) {
            nums[front++] = nums[pos++];	// Move non-zero.

            // Fine next non-zero.
            while (pos < n && nums[pos] == 0) pos++;
        }
        // Set zero on tail.
        for (int i = front; i < n; i++)
            nums[i] = 0;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> nums = {0, 1, 3, 0, 12};
	Solution s;
	s.moveZeroes(nums);

	for (int num: nums)
		cout << num << " ";
	cout << endl;

	return 0;
}