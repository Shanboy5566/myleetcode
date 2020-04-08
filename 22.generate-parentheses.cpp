/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtracking(ans, "", 0, 0, n);
        return ans;
    }
    
    void backtracking(vector<string>& ans, string current, int num_left_p, int num_right_p,  int n){
        // Goal
        if ( current.length() == n * 2){
            ans.push_back(current);
            return;
        }
        
        // Decision
        // Decision 1. '('
        if (num_left_p < n) backtracking(ans, current + '(', num_left_p + 1, num_right_p, n);
        // Decision 2. ')'
        if (num_right_p < num_left_p) backtracking(ans, current + ')', num_left_p, num_right_p + 1, n);
        
    }
};
// @lc code=end

