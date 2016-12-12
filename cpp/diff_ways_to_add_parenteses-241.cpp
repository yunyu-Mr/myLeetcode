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
        
        // Extract operators and numbers.
        extract (nums, operators, input);
        

        typedef std::vector<int>                             Vec1D;
        typedef std::vector<std::vector<int> >               Vec2D;
        typedef std::vector<std::vector<std::vector<int> > > Vec3D;

        // Initialize
        int   N = nums.size();   // Number of numbers.
        Vec3D dp (N, Vec2D());  // 3-dimensional, dp results.

        for (int num : nums)
            dp[0].push_back(Vec1D(1, num));
        
        int k = 2;
        for (; k <= N; k++)       // For each sub len.
        {
            for (int s = 0; s <= N - k; s++)      // For each start point.
            {
                dp[k-1].push_back(Vec1D());

                // Devide and conquer
                for (int i = s; i < s + k -1; i++)          // For each split point.
                {
                    char op = operators[i];
                    const vector<int>& result = merge(dp[i-s][s], dp[s+k-1-i-1][i+1], op);
                    // printVec(result);
                    auto it = dp[k-1][s].end();
                    dp[k-1][s].insert(it, result.begin(), result.end());
                }
            }
        }
        return dp[N-1][0];
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> res = s.diffWaysToCompute("2*3-4*5");
    printVec(res);
    return 0;
}