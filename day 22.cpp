class Solution {
public:

    void dfs(vector<vector<char>>& grid, int i, int j) {

        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds or water
        if (i < 0 || i >= m || j < 0 || j >= n ||
            grid[i][j] == '0') {
            return;
        }

        // Mark as visited
        grid[i][j] = '0';

        // Explore 4 directions
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1') {

                    // New island found
                    count++;

                    // Destroy/visit entire island
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};
