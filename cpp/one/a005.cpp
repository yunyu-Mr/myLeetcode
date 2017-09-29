#include <iostream>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    string longestPalindrome(string s) {
    	if (s.length() < 2) return s;

    	int h;  // substr start point.
    	unsigned int maxlen = 1; // max length

        for (int i = 1; i < s.length(); i++) {  // i is center
            // even length
            // {_len_} | i {_len_}
        	int len = min<unsigned int>(i, s.length()- i);
        	for (int l = 1; l <= len; l++) {
        		if (s[i-l] != s[i-1+l])
                    break;
        		if (2*l > maxlen) {
                    maxlen = 2*l;
        			h = i - l;
        		}
        	}
            // odd length
            // {_len_} | i | {_len_}
        	len = min<unsigned int>(i, s.length() - 1 - i);
        	for (int l = 1; l <= len; l++) {
        		if (s[i-l] != s[i+l]) 
                    break;
        		if (2*l + 1 > maxlen) {
                    maxlen = 2*l + 1;
        			h = i - l;
        		}
        	}
        }
        return s.substr(h, maxlen);
    }
};

int main(int argc, char const *argv[])
{
	Solution1 s1;
    cout << s1.longestPalindrome("abcda") << endl;
	cout << s1.longestPalindrome("abab") << endl;
	cout << s1.longestPalindrome("abababa") << endl;
	return 0;
}