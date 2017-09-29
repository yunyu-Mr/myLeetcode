#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
        	while (i > 0 && nums[i] == nums[i-1]) i++;  // drop dup
        	int t = -nums[i];  // target

            // two sum
        	int l = i + 1, h = nums.size() - 1;
        	while (l < h) {
        		if 		(nums[l] + nums[h] < t) l++;
        		else if (nums[l] + nums[h] > t) h--;
        		else {
        			results.push_back(vector<int>{nums[i], nums[l++], nums[h--]});
                    while (l < h && nums[l] == nums[l-1]) l++;  // drop dup
                    while (l < h && nums[h] == nums[h+1]) h--;
                }
        	}
        }

        return results;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> nums = {0, -1, -1, -1, 2, 2, 2, 4};
    vector<vector<int>> res = s.threeSum(nums);
	for (auto p : res)
		cout << p[0] << " " << p[1] << " " << p[2] << endl;
	return 0;
}