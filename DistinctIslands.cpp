#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int row, int col, int baseRow, int baseCol,
             vector<vector<int>>& grid, vector<vector<int>>& vis,
             vector<pair<int, int>>& shape) {
        vis[row][col] = 1;
        shape.push_back({row - baseRow, col - baseCol});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < grid.size() &&
                ncol >= 0 && ncol < grid[0].size() &&
                !vis[nrow][ncol] &&
                grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, baseRow, baseCol, grid, vis, shape);
            }
        }
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    vector<pair<int, int>> shape;
                    dfs(i, j, i, j, grid, vis, shape);
                    st.insert(shape);
                }
            }
        }
        return st.size();
    }
};