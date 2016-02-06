/*
 *	Fraction to Recurring Decimal
 *
 *  想法：模拟手算除法的过程
 *  注意：负数，溢出等问题
 */

#include <iostream>
#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution {
private:
	string int2string(long quo) {
		char buf[32] = "";
        sprintf(buf, "%ld", quo);
        return string(buf);
	}
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res = "";

        // Solve negative problem
        if ((numerator < 0 && denominator > 0) ||
        	 (numerator > 0 && denominator < 0) )
        	res += "-";
        // Fix overflow problem (-2147483648)
        long num = abs((long)numerator);
        long den = abs((long)denominator);
        // Quo and Remainder
        long quo = num / den,
        	 rem = num % den;
        // Hash table, check circular
        unordered_map<long, int> hash;

        // add quo
        res += int2string(quo);
        if (rem != 0) {
        	res += ".";		// add dot
        	num = 10 * rem;
        	hash[num] = res.length();
        }else
        	return res;
        // if rem is 0, finish;
        // or, check circular, finish.
        while (rem) {
        	rem = num % den;
        	quo = num / den;
        	num = 10 * rem;

        	res += int2string(quo);

        	if (hash.find(num) != hash.end()) {
        		int bk = hash[num];
        		// Add bracket and break
        		res = res.substr(0, bk) 
        				+ "(" 
        				+ res.substr(bk, res.length()) 
        				+ ")";
        		break;
        	}else
        		hash[num] = res.length();
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout<<"1/6 = "<<s.fractionToDecimal(1,6)<<endl;
	cout<<"2/3 = "<<s.fractionToDecimal(2,3)<<endl;
	cout<<"1/7 = "<<s.fractionToDecimal(1,7)<<endl;
	cout<<"-1/-2147483648 = "<<s.fractionToDecimal(-1,-2147483648)<<endl;
	return 0;
}