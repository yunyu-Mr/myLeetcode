#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<vector<char> > zigzag(numRows, vector<char>());
        
        int row = -1;       // which row
        int inc = 1;        // increament (1 or -1)
        bool isDown = true;  //direction (up or down?)
        for (char c : s) {
            row += inc;
            zigzag[row].push_back(c);
            
            if (isDown && row == numRows -1){
                isDown = false;
                inc = -1;
            } else if (!isDown && row == 0){
                isDown = true;
                inc = 1;
            }
        }
        
        // Reshape string, iterate line by line.
        int i = 0;
        for (auto line : zigzag)
            for (char c : line)
                s[i++] = c;
        return s;
    }
};