/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        /*
        max only occurs in "self" or "self" + previous max
        */
        int max_now = 0, max_res = INT_MIN;
        int left = 0, right = 0;
        while (right < nums.size())
        {
            if (nums[right] > max_now + nums[right])
            {
                max_now = nums[right];
                left = right;
                right++;
            }
            else
            {
                max_now += nums[right];
                right++;
            }
            max_res = max(max_res, max_now);
        }
        return max_res;
    }
};
// @lc code=end
