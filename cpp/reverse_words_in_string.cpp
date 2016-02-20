#include <iostream>
// #include <vector>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
    	if (s == "") return;

    	string res = "";

    	// trim start blanks
    	int k = 0;
    	for (; k < s.length(); ++k)
    		if (s[k] != ' ')
    			break;
    	s = s.substr(k, s.length());

    	// trim end blanks
    	int j, i = s.length() - 1;

    	while (i > 0 && s[i] == ' ') { --i; }
    	j = i;

    	// split and append
    	for (; i >= 0; --i) {
    		if (s[i] == ' ') {
    			res += s.substr(i+1, j - i) + " ";
    			while (i > 0 && s[i] == ' ') 
    				--i;
    			j = i;
    			if (i == 0) break;
    			continue;
    		}
    	}

    	// add the last word
    	i = (i<0)? 0:i;
    	// cout<<"i = "<<i<<" j = "<<j<<endl;
    	res += s.substr(i, j - i + 1);
    	s = res;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	string str = "  The sky is    blue ";
	string str2 = "  a   b";
	s.reverseWords(str);
	s.reverseWords(str2);
	cout<<str<<"end"<<endl;
	cout<<str2<<"end"<<endl;
	return 0;
}