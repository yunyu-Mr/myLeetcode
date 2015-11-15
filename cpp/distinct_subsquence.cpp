#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
    	int m = t.length(),
    		n = s.length();

    	if (m < 1 || n < 1 || m > n)
    		return 0;

        vector<vector<int>> mtx(m+1, vector<int>(n+1));

        // src string is empty
        for (int i = 0; i < m+1; ++i)
        	mtx[i][0] = 0;
        // src string is empty
        for (int j = 1; j < n+1; ++j) {
        	mtx[0][j] = 0;		// i = 0
        	mtx[1][j] = mtx[1][j-1] + (t[m-1] == s[n-j]);  //i = 1
        }

        for (int i=2; i < m+1; ++i)
        	for (int j=1; j < n+1; ++j)
        	{
        		// target is longer than src string
        		if (i > j)
        		{
        			mtx[i][j] = 0;
        			continue;
        		}
        		// Check the first char
        		if (t[m-i] != s[n-j])
        		{
        			mtx[i][j] = mtx[i][j-1];  // The first chars are not the same, skip the first of src string.
        		}
        		else {
        			mtx[i][j] = mtx[i-1][j-1] + mtx[i][j-1]; // The first chars are the same, sum of them.
        		}
        	}
        return mtx[m][n];
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	s.numDistinct("rabbbit", "rabbit");
	return 0;
}