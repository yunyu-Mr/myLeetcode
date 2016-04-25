#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)
            return 0;
        
        int cnt = 0;
        int *check = new int[n+1];
        memset(check, 0, (n+1) * sizeof(int));
        
        for (int i = 1; i <= n; ++i)
            if (check[i] == 0 && isPrime(i)){
                check[i] = 1;
                cnt++;
                
                // cout<<i<<endl;
                
                int mul = 2;
                while (1) {
                    int p = i*mul++;
                    if (p <= n)
                        check[p] = 1;
                    else
                        break;
                }
            }
            
        // for (int i=0; i<=n; i++)
        //     cout<<check[i]<<" ";
        cout<<cnt<<endl;
        return cnt;
    }
    
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        int limit = sqrt(n);
        for (int i = 2; i<= limit; ++i) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    s.countPrimes(10);
    return 0;
}
