#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        // Sort candidates list.
        std::sort(candidates.begin(), candidates.end());
        
        vector<vector<int> > com_list;
        vector<int> possible;
        
        if (candidates.size() == 0)
            return com_list;
        
        // Backtracking
        backtracking(com_list, possible, candidates, target, 0, 0);
        
        return com_list;
    }
    
    void backtracking(vector<vector<int> >& com_list, 
                    vector<int>& possible, 
                    vector<int>& candidates, 
                    int target, 
                    int sum, 
                    int k)
    {
        if (k == candidates.size()){
            if (sum == target)
                com_list.push_back(possible);
            return;
        }
        
        // Count same val number.
        int nSame = 1, i = k;
        while (i < candidates.size()-1) {
            if (candidates[i] == candidates[i+1]) {
                nSame++;
                i++;
            }
            else break;
        }

        // Not include.
        backtracking(com_list, possible, candidates, target, sum, k + nSame);
        // Include N same candidates.
        for (i = 1; i <= nSame; i++) {
            sum += candidates[k];
            // Cut branches.
            if (sum >target)
                return;
            for (int j = 1; j <= i; j++)
                possible.push_back(candidates[k]);
            // backtracking
            backtracking(com_list, possible, candidates, target, sum, k + nSame);
            for (int j = 1; j <= i; j++)
                possible.pop_back();
        }        
    }
};

int main() {
    Solution s;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    
    vector<vector<int> > comlist = s.combinationSum2(candidates, 8);
    
    for (auto com : comlist) {
        for (auto v : com)
            cout << v << "  ";
        cout << endl;
    }
    return 0;
}