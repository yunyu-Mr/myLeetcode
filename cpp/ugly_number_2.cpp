#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    long findMin(vector<long> &hp) {
        long e = hp.front();
        do {
            pop_heap(hp.begin(), hp.end()); hp.pop_back();
        } while(e == hp.front());
        return -e;
    }
    
public:
    int nthUglyNumber(int n) {
        int factor[3] = {2,3,5};
        vector<long> ugly = {1};
        vector<long> hp;
        make_heap(hp.begin(), hp.end());
        
        int k = 1;
        while (k < n) {
            for (int i = 0; i < 3; i++) {
                hp.push_back(- ugly[k-1] * factor[i]);
                push_heap(hp.begin(), hp.end());
            }
            
            ugly.push_back(findMin(hp));
            // cout << ugly[k-1] << endl;
            k++;
        }
        return ugly[n-1];
    }
};

int main() {
    Solution s;
    cout << s.nthUglyNumber(1407);
    return 0;
}