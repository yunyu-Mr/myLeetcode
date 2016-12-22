#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    // Define operator.
	int cal(const int& lhs, const int& rhs, const char& op) {
		if (op == '+')
			return lhs + rhs;
		return lhs - rhs;
	}

    /**
     * [calculate Two stack method]
     * @param  s [string]
     * @return   [int]
     */
    int calculate(string s) {
        stack<int> nums;        // store numbers.
        stack<char> operators;  // store operatoers.

        int i = 0;
        int res = 0, rhs;       // result and right num.
        char op = '+';          // operator

        while (i < s.length()) {
        	char c = s[i];
        	switch (c) {
        		case '+':
        		case '-':
                    op = c;
                    break;
        		case '(':
                    // Save previous result.
                    nums.push(res);
                    operators.push(op);
                    // Save '('.
                    operators.push(c);
                    // Reset
                    res = 0;
                    op = '+';
        			break;
        		case ')':
                    operators.pop(); // pop '('
                    rhs = res;                              // current result shift to right.
                    res = nums.top(); nums.pop();           // restore result
                    op = operators.top(); operators.pop();  // restore operator
                    res = cal (res, rhs, op);
        			break;
        		case ' ':
        			break;
        		default:
                    // Get a num.
                    int j = i + 1;
                    while (j < s.length()) {
                        char n = s[j];
                        if (n == '+' || n == '-' || n == ' ' || n == ')' || n == '(')
                            break;
                        j++;
                    }
                    // 
                    if (operators.empty() || operators.top() == '(')
                        res  = cal(res, stoi(s.substr(i, j-i)), op);
                    i = j - 1;  // increase later.
        	}
            i++;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
    cout << s.calculate("2-1 +2 ") << endl;
    cout << s.calculate("1 - (5)") << endl;
	cout << s.calculate(" (1+(4+5+2)-3)+ (6 + 8) ") << endl;
	return 0;
}