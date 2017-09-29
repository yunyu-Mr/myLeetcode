#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAlphaNumeric(char c) {
        return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }

    bool isCharEq(char a, char b){
    	if (a <= '9' && b <= '9') return a == b;    // numerical
    	return tolower(a) == tolower(b);			// alpha, compare lowercase
    }
    
    bool isPalindrome(string s) {
        int N = s.length();
        if (N == 0) return true;
        
        for (int i = 0, j = N-1; i < j; i++, j--) {
            while (i < N  && !isAlphaNumeric(s[i])) i++;   // Ignore non-alphanumeric char.
            while (j >= 0 && !isAlphaNumeric(s[j])) j--;
            
            if      (i >= j)       			break; 		  // Go through whole string but not found char to be compared
            else if (!isCharEq(s[i] ,s[j])) return false; // Not equal, non palindrome (i < j)
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
	Solution S;
	cout << S.isPalindrome("race a car");
	cout << S.isPalindrome("A man, a plan, a canal: Panama");
	return 0;
}