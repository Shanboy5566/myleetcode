/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ans;
        h = board.size();
        w = board[0].size();
        for (int x = 0; x < h; x++){
            for (int y = 0; y < w; y++){
                if (confirm(board, word, x, y, 0)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    int h;
    int w;
    bool confirm(vector<vector<char>>& board, string& word, int x, int y, int iter){
        if (x < 0 || y < 0 || x >= h || y >= w || board[x][y] != word[iter] ){
            return false;
        }
        // cout << "x: " << x << endl;
        // cout << "y: " << y << endl;
        // cout << "iter: " << iter << endl;
        if (iter == word.length() - 1){
            return true;
        }
        // can not go back!!
        char current = board[x][y];
        board[x][y] = 0;
        int num = ++iter;
        bool ok = confirm(board, word, x+1, y, num) || confirm(board, word, x, y+1, num) || confirm(board, word, x-1, y, num) || confirm(board, word, x, y-1, num);
        // after check up down left right, recover
        board[x][y] = current;
        // cout << "ok: " << ok << endl;
        return ok;
    }
};
// @lc code=end

