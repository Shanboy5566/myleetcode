/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        ios_base::sync_with_stdio(false);
        if (grid.empty() || grid[0].empty()) return 0;

        int m = grid.size(), n = grid[0].size();
        int island_cnt = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                // if is water and visited, go next
                if (grid[i][j] == '0' || visited[i][j]) continue;
                // DFS
                dfs(grid, visited, i, j);
                island_cnt++;
            }
        }
        return island_cnt;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
        // if out of grid or water, return
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size()|| grid[i][j] == '0' || visited[i][j]) return;

        visited[i][j] = true;
        dfs(grid, visited, i-1, j); // up
        dfs(grid, visited, i+1, j); // down
        dfs(grid, visited, i, j-1); // left
        dfs(grid, visited, i, j+1); // right
    }


};
// @lc code=end

