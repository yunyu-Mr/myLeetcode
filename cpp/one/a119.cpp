class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex + 1;
        vector<int> row(n, 1);
        
        for (int i = 2; i < n; i++)
            for (int j = i-1; j > 0; j--)
                row[j] += row[j-1];
        
        return row;
    }
};