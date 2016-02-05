/*
 *	Repeated DNA Sequences
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> hash;
        vector<string> res;

        if (s.length() <= 10)
        	return res;

        for (int i = 0; i <= s.length()-10; ++i) {
        	string sub = s.substr(i, 10);
        	if (hash.find(sub) != hash.end()) {
        		if (hash[sub] == 1) {
        			res.push_back(sub);
        			hash[sub] = 2;
        		}

        	}
        	else
        		hash[sub] = 1;
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<string> sq = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	for (int i = 0; i < sq.size(); ++i)
		cout<<sq[i]<<endl;
	return 0;
}