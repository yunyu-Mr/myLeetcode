/*
 *	Larget Number
 */

#include <iostream>
#include <algorithm>	//std::sort
#include <vector>

using namespace std;

bool strComp(const std::string &x, const std::string &y) {
	// if xy > yx, then x > y (return true);
	// else y > x (return false);
	return x+y > y+x;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ns;
        string res = "";
        // int to string
        for (int num : nums)
        	ns.push_back(std::to_string(num));
        // sort the vector
        std::sort(ns.begin(), ns.end(), strComp);
        // in case 0000...0000
        if (ns[0] == "0") return "0";
        // concate string
        for (string str : ns) 
        	res += str;
        
        return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> nums = {78,100,34,4,3,2,1};
	cout<<s.largestNumber(nums)<<endl;
	return 0;
}