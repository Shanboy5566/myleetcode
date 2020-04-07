/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int n = nums.size() - 1;
        int end_index = n;
        for (int i = n; i >= 0; i--){
            if (i + nums[i] >= end_index) end_index = i;
        }
        return end_index == 0;
    }
};
// @lc code=end

