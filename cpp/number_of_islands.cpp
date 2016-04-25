// std=c++11
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    int m, n;
    // Queue for BFS. Store vetex.
    queue<pair<int,int> > Q;
    // Check whether adjacent points are land or water?
    void enqueue(int i, int j, vector<vector<char> >& grid, vector<vector<bool> >&color) {
        // Left
        if (i > 0 && grid[i-1][j] == '1' && color[i-1][j] == 0) {
            color[i-1][j] = 1;
            Q.push(make_pair(i-1, j));
        }
        // Right
        if (i < m-1 && grid[i+1][j] == '1' && color[i+1][j] == 0){
             color[i+1][j] = 1;
             Q.push(make_pair(i+1, j));
        }
        // Below
        if (j < n-1 && grid[i][j+1] == '1' && color[i][j+1] == 0){
             color[i][j+1] = 1;
             Q.push(make_pair(i, j+1));
         }
         // Upper
         if (j > 0 && grid[i][j-1] == '1' && color[i][j-1] == 0){
             color[i][j-1] = 1;
             Q.push(make_pair(i, j-1));
         }
    }
public:
    int numIslands(vector<vector<char> >& grid) {
        m = grid.size();
        if (m <= 0)
            return 0;
        n = grid[0].size();
        if (n <= 0)
            return 0;
            
        int num = 0;
        vector<vector<bool> >  color(m, vector<bool>(n, 0));  // 2d array
        
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '1' && color[i][j] == 0) {
                    // Breath first search. Expand and mark a island.
                    color[i][j] = 1;
                    Q.push(make_pair(i,j));
                    while (!Q.empty()) {
                        pair<int,int> v = Q.front(); Q.pop();
                        enqueue(v.first, v.second, grid, color);
                    }
                    // One island found.
                    num++;
                }
        return num;
    }
};

int main() {
    Solution s;
    // C++11 initialize method
    vector<vector<char> > grid = {
        {'0','0','1'},
        {'0','1','0'},
        {'0','1','0'}
    };
    cout << s.numIslands(grid);
}