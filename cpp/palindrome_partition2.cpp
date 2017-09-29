/*
 *	Palindrome Partitioning II
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCut(string s) {
    	int n = s.length();
        vector<vector<int> > m(n+1, vector<int>(n+1));  // default init to 0

        for (int i = 2; i < n+1; ++i) {
        	for (int j = 0; j < n - i + 1; ++j) 
        	{
        		if (isPalindrome(s, j, j+i-1))  { // is palindrome
        			m[i][j] = 0;
        			continue;
        		}
        		else 
        		{
        			m[i][j] = i;
        			for (int k = 1; k < i; ++k) {
        				// printf("i=%d, j=%d \t k=%d  %d  %d\n", i, j, k, i-k, j+k);
        				m[i][j] = min(m[i][j], m[k][j] + m[i-k][j+k] + 1);
        			}
        		
        		}
        	}
        }
        return m[n][0];
    }

    bool isPalindrome(const string &s, int start, int end) {
    	while (start < end) {
    		if (s[start] != s[end])
    			return false;
    		start++;
    		end--;
    	}
    	return true;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout<<s.minCut("adabdc")<<endl;;
	return 0;
}