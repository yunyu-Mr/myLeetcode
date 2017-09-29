#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return vector<int>{-1, -1};
        
        return bSearchRange(nums, 0, nums.size()-1, target);
    }
    
    // Recursive search.
    vector<int> bSearchRange(vector<int>& nums, int i, int j, int target) {
        if (i > j) return vector<int>{-1, -1};
        
        if (i == j) {
            if (nums[i] == target) return vector<int>{i, i};
            else                   return vector<int>{-1, -1};
        }

        int m = (i + j) / 2;
        if      (target > nums[m]) return bSearchRange(nums, m+1, j, target);
        else if (target < nums[m]) return bSearchRange(nums, i, m, target);
        else if (target == nums[m]) {
            const vector<int>& left  = bSearchRange(nums, i, m-1, target);
            const vector<int>& right = bSearchRange(nums, m+1, j, target);
            return vector<int>{
                (left[0] == -1)? m : left[0], 
                (right[1] == -1)? m : right[1]
            };
        }
        return vector<int>{-1,-1};
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {5,7,7,8,8,9};
    vector<int> res = s.searchRange(nums, 8);
    cout << res[0] << "\t" << res[1]<< endl;
    return 0;
}