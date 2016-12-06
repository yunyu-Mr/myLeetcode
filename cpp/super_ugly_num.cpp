#include <iostream>
#include <queue>
using namespace std;

/*
 * ugly number:
 *     u1, u2, u3, u4, u5, ...
 * primes:
 *     [p1, p2, p3]
 *
 * L1: p1 *u1, p1 *u2, p1 *u3, p1 *u4, p1 *u5, ...
 * L2: p2 *u1, p2 *u2, p2 *u3, p2 *u4, p2 *u5, ...
 * L3: p3 *u1, p3 *u2, p3 *u3, p3 *u4, p3 *u5, ...
 *
 * Merge L1, L2, L3, ...
 *    Use heap, each time get a minimum ugly num.
 */
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> uglys(n, 0);    // ugly number list.
        vector<int> indexs(primes.size(), 0);   // index of each list.
        int idx;  // index of prime list.

        std::priority_queue<pair<int, int> > q;
        for (int idx = 0; idx < primes.size(); idx++)
            q.push (make_pair(-primes[idx], idx));

        uglys[0] = 1;
        for (int i = 1; i < n;) {
            if (uglys[i-1] != -q.top().first)
                uglys[i++] =  -q.top().first;
            // cout << uglys[i-1] << endl;
            idx = q.top().second;
            indexs[idx]++;
            q.pop();

            q.push(make_pair(-uglys[indexs[idx]] * primes[idx], idx));
        }

        return uglys[n-1];
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> primes = {2,7,13,19};
	cout << s.nthSuperUglyNumber(1, primes) << endl;
	cout << s.nthSuperUglyNumber(12, primes) << endl;

    std::vector<int> primes2 = {
        7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251
    };
    cout << s.nthSuperUglyNumber(100000, primes2) << endl;
	return 0;
}