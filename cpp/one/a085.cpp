class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        
        vector<vector<int>> left(m, vector<int>(n, -1)),
                            right(m, vector<int>(n, n)),
                            height(m, vector<int>(n, 0));
        
        // Init
        int area = 0;
        for (int r = 0; r < n;)
        {
            if (matrix[0][r] == '1') {
                int l = r;  // current left bound
                while (r < n && matrix[0][r] == '1')
                    r++;    // current right bound
                    
                for (int j = l; j < r; j++) {
                    left[0][j] = l;
                    right[0][j] = r;
                    height[0][j] = 1;   // first row height is 1
                }
                area = max (area, r - l);
            } else r++;
        }
        
        // DP
        for (int i = 1; i < m; i++)
            for (int r = 0; r < n;) {
                
                if (matrix[i][r] == '1') {
                    int l = r;
                    while (r < n && matrix[i][r] == '1')
                        r++;

                    for (int j = l; j < r; j++) {
                        left[i][j]  = max (l, left[i-1][j]);
                        right[i][j] = min (r, right[i-1][j]);
                        
                        if (matrix[i-1][j])
                            height[i][j] = height[i-1][j] + 1;
                        else
                            height[i][j] = 1;
                        // cout << j << ": " << l << " " << r << " " << height[i][j] << endl;
                        area = max (area, (right[i][j] - left[i][j]) * height[i][j]);
                    }
                } else r++;
            }
        
        return area;
    }
};