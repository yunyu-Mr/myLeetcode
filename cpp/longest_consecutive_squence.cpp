#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    	// Set up set
    	unordered_set<int> numsSet;
        for (int i = 0; i < nums.size(); i++) 
        	numsSet.insert(nums[i]);
        // longest length
        int longest = 0;
        //
        for (int i = 0; i < nums.size(); i++) {
        	if (numsSet.find(nums[i]) == numsSet.end())
        		continue;
        	// Tmp length
        	int l = 0;
        	// Grow upward
        	int k = nums[i]+1;
        	while (numsSet.find(k) != numsSet.end()) {
        		numsSet.erase(k);
        		k++;
        		l++;
        	}
        	// Grow downward
        	k = nums[i] -1;
        	while (numsSet.find(k) != numsSet.end()) {
        		numsSet.erase(k);
        		k--;
        		l++;
        	}
        	// Refresh longest length
        	longest = max(longest, l+1);
        }

        return longest;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> nums = {1,2,3,3,100,200};
    cout<<"\n\n\n"<<s.longestConsecutive(nums);
	return 0;
}