#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string st[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0) return res;

        res = backtracking(digits, 0);
        return res;
    }
    
    vector<string> backtracking(const string & digits, int i) {
        vector<string> res;
        if (i == digits.length()) return vector<string>{""};
        
        int d = digits[i] - '0';
        const string& candidate = st[d];
        
        for (int j = 0; j < candidate.length(); j++)
            for (auto s : backtracking(digits, i+1))
                res.push_back(candidate[j] + s);
        return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<string> res = s.letterCombinations(argv[1]);
	for (auto s : res)
		cout << s << endl;
	return 0;
}