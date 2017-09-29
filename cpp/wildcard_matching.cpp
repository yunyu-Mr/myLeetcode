#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
    	cout<<"s: "<<s<<"\tp: "<<p<<endl;
    	if (p.length() == 0 && s.length() == 0)
    		return true;
        if (p.length() == 0 && s.length() != 0) 
        	return false;

        if (s.length() == 0 && (p[0] == '*' || p[0] == '?'))
        	return true;
        if (p[0] == s[0] || p[0] == '?')
        	return isMatch(s.substr(1, s.length()), p.substr(1, p.length()));
        if (p[0] == '*'){
        	int i = 0;
        	while (i < s.length() && s[i+1] == s[i])
        		++i;
        	return isMatch(s.substr(i+1, s.length()), p.substr(1, p.length()));
    	}
    	return false;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout<<s.isMatch("abefcdgiescdfimde", "ab*cd?i*de");
	return 0;
}