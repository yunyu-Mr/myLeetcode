#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if (n <= 1)
            return 1;
        // Dynamic programming table.
        vector<int> m(n+1, n);
        // Initialize.
        m[0] = 0;
        m[1] = 1;
        // O(n*log(n))
        // e.g. m[5] = min( 5, 1 + m[5-1], 1 + m[5-4] )
        for (int k = 2; k <= n; k++) {
            m[k] = k;  // worst case: 1+1+1+...+1
            for (int i = 1; i*i <= k; ++i) {
                m[k] = min(m[k], 1 + m[k-i*i]);
            }
        }
        // for (int i = 0; i < m.size(); i++){
        //     cout << m[i] << " ";
        // }
        return m[n];
    }
};

int main() {
    Solution s;
    s.numSquares(12);
}