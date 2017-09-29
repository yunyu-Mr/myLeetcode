class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0) return 0;
        
        vector<int> path(n, 0);     // Store minimum pathSum to leaves.
        path[0] = triangle[0][0];
        
        for (int i = 1; i < n; i++) {
            path[i] = path[i-1] + triangle[i][i];       // right-most path sum
            for (int j = i-1; j >= 1; j--)
                path[j] = min(path[j], path[j-1]) + triangle[i][j];  // choose min path sum
            path[0] = path[0] + triangle[i][0];         // left-most path sum
        }
        // Return min path
        int m = path[0];
        for (int p : path)
            if (p < m) m = p;
        return m;
    }
};