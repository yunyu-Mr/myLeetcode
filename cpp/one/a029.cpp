#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        // if (divisor == 1) return dividend;  // ensure result would not INT_MIN

        long ldivisor = abs((long)divisor);
        long ldividend = abs((long)dividend);

        bool isNeg = ((dividend < 0) != (divisor < 0));

        int result = 0;
        while (ldividend >= ldivisor) {
        	int m = 0;
        	for (; ldividend >= (ldivisor << m); m++);
        	m--;
        	ldividend -= (ldivisor << m);
        	result += 1 << m;
        }

        return isNeg ? -result : result;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int dividend = atoi(argv[1]);
	int divisor = atoi(argv[2]);
	cout << s.divide(dividend, divisor) << endl;
	return 0;
}