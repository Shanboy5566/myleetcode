/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                int num_live = 0;
                // Scan Region
                for (int x = max(0, j - 1); x < min(n, j + 2); x++){
                    for (int y = max(0, i - 1); y < min(m, i + 2); y++){
                        if (x == j && y == i) continue;
                        num_live += board[y][x] & 1;
                    }
                }
                // Rule 1, Rule 3
                // if (num_live < 2 || num_live > 3)  // died on to next
                // Rule 2
                if (board[i][j] ==1 && (num_live == 2 || num_live == 3)) board[i][j] |= 0b10; // lives on to next
                // Rule 4
                if (board[i][j] == 0 && num_live == 3) board[i][j] |= 0b10;  // lives on to next
            }
        }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                board[i][j] >>= 1;
            }
        }
    }
};
// @lc code=end

