#include <iostream>
#include <vector>
using namespace std;

/**
 * Print vector.
 */
void
printVec(const vector<int> &nums){
    for (int num : nums)
        cout << num << " ";
    cout << endl;
}

/**
 * My solutiion.
 */
class Solution {
public:
    // Calculator.
    int calculate(int a, int b, char op) {
        int result = -1;
        switch(op) {
            case '+':
                result = a + b; break;
            case '-':
                result = a - b; break;
            case '*':
                result = a * b;
        }
        return result;
    }
    
    // Merge two list.
    vector<int> merge(const vector<int> &left, const vector<int> &right, const char &op)
    {
        vector<int> result;

        for (int l: left)
            for (int r: right)
                result.push_back (calculate (l, r, op));
        return result;
    }

    // Extract numbers and operators from input string.
    void extract(vector<int> &nums, vector<char> &operators, const string &input) {
        int i = 0, j = 0;
        while (j < input.length()) {
            char c = input[j];
            if (c == '*' || c == '-' || c == '+') {
                operators.push_back(c);
                nums.push_back(stoi(input.substr(i, j - i)));
                i = ++j;
            }
            j++;
        }
        nums.push_back(stoi(input.substr(i, j)));
    }
    
    /**
     * Using dynamic programming (Bottom up).
     * Also, it's a divide and conquer method.
     */
    vector<int> diffWaysToCompute(string input) {
        vector<char> operators;
        vector<int> nums;
        // 3-dimensional dp results:
        vector<vector<vector<int> > > dp;
        
        // Extract operators and numbers.
        extract (nums, operators, input);
        
        //
        int k = 1;  // sub calcu's length.
        // Init
        vector<vector<int> > tmp;
        for (int num : nums) {
            vector<int> e(1, num);
            tmp.push_back(e);
        }
        dp.push_back(tmp);
        
        k = 2;
        for (; k <= nums.size(); k++)       // For each sub len.
        {
            vector<vector<int> > tmp;
            dp.push_back(tmp);

            for (int s = 0; s <= nums.size() - k; s++)      // For each start point.
            {
                dp[k-1].push_back(vector<int>());

                // Devide and conquer
                for (int i = s; i < s + k -1; i++)          // For each split point.
                {
                    char op = operators[i];
                    vector<int> result = merge(dp[i-s][s], dp[s+k-1-i-1][i+1], op);
                    // printVec(result);
                    auto it = dp[k-1][s].end();
                    dp[k-1][s].insert(it, result.begin(), result.end());
                }
            }
        }
        return dp[k-2][0];
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> res = s.diffWaysToCompute("2*3-4*5");
    printVec(res);
    return 0;
}