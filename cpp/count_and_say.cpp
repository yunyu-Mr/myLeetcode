#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 0)
            return "";
            
        string say("1");
        
        if (n == 1)
            return say;
        for (int i = 1; i < n; i++) {
            string newSay = "";
            int count = 1;
            for (int j = 0; j < say.length() - 1; j++) {
                if (say[j] == say[j+1]) {
                    count ++;
                }else {
                    newSay += to_string(count) + say[j];
                    count = 1;
                }
            }
            // Remember the last string.
            newSay += to_string(count) + say[say.length() -1];
            // cout << newSay << endl;
            say = newSay;
        }
        
        return say;
    }
};

int main() {
    Solution s;
    s.countAndSay(6);
    // for (int i = 0; i < 6; i++)
        // s.countAndSay(i);
        // cout << s.countAndSay(i) << endl;
    return 0;
}