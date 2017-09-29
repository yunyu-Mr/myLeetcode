#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int i, int j, int target) {
        while (i < j) {
            int m = (i + j) / 2;
            if   (target <= nums[m]) j = m;
            else                     i = m + 1;
        }
        return (target == nums[i]) ? i : -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        if (nums[0] < nums[n-1])        // without rotated
            return binarySearch(nums, 0, n-1, target);
        
        // Find the break point.
        int i = 0,
            j = n - 1;

        while (i < j - 1) {
            int m = (i + j) / 2;
            if   (nums[m] > nums[i]) i = m;
            else j = m;
        }
        // choose left or right
        if (target >= nums[0] && target <= nums[i])
            return binarySearch(nums, 0, i, target);
        else if (target >= nums[j] && target <= nums[n-1])
            return binarySearch(nums, j, n-1, target);
        return -1;
    }

};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {3,1};
    cout << s.search(nums, 1) << endl;
    return 0;
}