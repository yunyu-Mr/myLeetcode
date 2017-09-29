class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        
        int k = 0, p = m*n-1;
        while (k < p) {
            int mid = (k + p) / 2;
            // Convert 1D index to 2D.
            int i = mid / n,
                j = mid % n;
            if      (target > matrix[i][j]) k = mid +1;
            else if (target < matrix[i][j]) p = mid;
            else return true;
        }
        return matrix[k/n][k%n] == target;
    }
};