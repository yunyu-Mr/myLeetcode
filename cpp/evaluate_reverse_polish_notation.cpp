/*
 * 	Evaluate Reverse Polish Notation
 */

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	char getType(const string& token) {
		if (token == "+")
			return '+';
		if (token == "-")
			return '-';
		if (token == "/")
			return '/';
		if (token == "*")
			return '*';
		return 'n';
	}

    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string token : tokens) {
        	char type = getType(token);

        	if (getType(token) == 'n')
        		s.push(stoi(token.c_str()));
        	else {
        		// Pop top two num and calculate, then push.
        		int rhs = s.top(); s.pop();
        		int lhs = s.top(); s.pop();
        		switch (type) {
        			case '+':
        				s.push(lhs + rhs); break;
        			case '-':
        				s.push(lhs - rhs); break;
        			case '*':
        				s.push(lhs * rhs); break;
        			case '/':
        				s.push(lhs / rhs); break;
        		}
        	}
        }
        return s.top();
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<string> tokens = {"4","13","5","/","+"};
	vector<string> tokens2 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
	cout<<s.evalRPN(tokens2)<<endl;
	return 0;
}