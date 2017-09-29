#include <iostream>
using namespace std;

class Solution {
public:
    int getDigit(int x, int i) {
        return (x / i) % 10;
    }
    bool isPalindrome(int x) {
        if (x < 0)  return false;
        if (x < 10) return true;
        
        // How many digits ?
        long tens = 1;      // In case overflow!!!
        while (x >= 10 * tens) tens *= 10;

        // Compare two pointers.
        int h = tens, l = 1;
        while (h > l) {
            if (getDigit(x, h) != getDigit(x, l))
                return false;
            h /= 10;
            l *= 10;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int x = atoi(argv[1]);
    cout << s.isPalindrome(x) << endl;
    return 0;
}