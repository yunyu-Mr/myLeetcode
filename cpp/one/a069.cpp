class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        long i = 1, j = x/2 +1;
        while (i < j-1) {
            long m = (i + j) / 2;
            // m^2 must less than x or equal x.
            if      (x > m*m) i = m;
            else if (x < m*m) j = m-1;
            else return m;
        }
        return (j*j <= x) ? j : j-1;
    }
};