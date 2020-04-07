/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /*
        size = 7
        1, 2, 1, 3, 5, 6, 4

        size = 4
        1, 2, 3, 1
        */
    //    if (nums.size() == 1) return 0;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2; // avoid overflow
            if (nums[m] > nums[m + 1])
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
// @lc code=end

