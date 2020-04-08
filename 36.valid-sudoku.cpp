/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_set<string> seen;
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.'){
                    // seen.insert("Fuck with row " + i)
                    // seen.insert("Fuck with col " + j)
                    // seen.insert("Fuck with sub_box " + i/3 + "-" + j/3)
                    // cout << !seen.insert("Fuck with row " + i).second << endl;
                    // cout << !seen.insert("Fuck with col " + j).second << endl;
                    // cout << !seen.insert("Fuck with sub_box " + to_string(i/3) + '-' + to_string(j/3)).second << endl;
                    // if (!seen.insert("Fuck with sub_box " + to_string(i/3) + '-' + to_string(j/3)).second) cout << "ths" << endl;
                    // if (!1) cout << "00" << endl;
                    if (!seen.insert("Fuck with row " + to_string(i) + " is " + board[i][j]).second
                        || !seen.insert("Fuck with col " + to_string(j) + " is " + board[i][j]).second
                        || !seen.insert("Fuck with sub_box " + to_string(i/3) + '-' + to_string(j/3) + " is " + board[i][j]).second) return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

