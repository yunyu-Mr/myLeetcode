#include <climits>

class Solution {
public:
    int reverse(int x) {
        bool isNeg = false;
        if (x < 0) {
            if (x == INT_MIN)  // edge case, int: [-2147483648 ~ 2147483647]
                return 0;
            isNeg = true;
            x = -x;
        }
        
        long y = 0;
        while (x >= 10) {
            y = 10 * y + x % 10;
            x = x / 10;
        }
        
        if (x > 0) 
            y = 10 * y + x;
            
        if (y > INT_MAX) return 0;  // overflow
        
        return isNeg? -y : y;
    }
};