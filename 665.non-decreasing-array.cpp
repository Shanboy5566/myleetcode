/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 */

// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        // brute force O(N)
        int mod = 0;
        nums.push_back(INT_MAX);
        for (int i = 1; i < nums.size() && mod < 2; i++){
            if (nums[i] < nums[i-1]){
                if (nums[i+1] > nums[i-1]) nums[i] = nums[i-1];
                else nums[i-1] = nums[i];
                mod++;
            }
        }
        if (mod > 1) return false;

        for (int i = 1; i < nums.size(); i++){
            if (nums[i] < nums[i-1]) return false;
        }

        return true;
        
    }
};
// @lc code=end

