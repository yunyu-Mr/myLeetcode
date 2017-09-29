class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<int> row(9, 0);
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.' && ++row[c - '1'] > 1)
                    return false;
            }
        }
        for (int j = 0; j < 9; j++) {
            vector<int> col(9, 0);
            for (int i = 0; i < 9; i++) {
                char c = board[i][j];
                if (c != '.' && ++col[c - '1'] > 1)
                    return false;
            }
        }
        for (int k = 0; k < 3; k++)
            for (int l = 0; l < 3; l++) {
                vector<int> cube(9, 0);
                for (int i = 3*k; i < 3*k + 3; i++)
                    for (int j = 3*l; j < 3*l + 3; j++) {
                        char c = board[i][j];
                        if (c != '.' && ++cube[c - '1'] > 1)
                            return false;
                    }
            }
        return true;
    }
};