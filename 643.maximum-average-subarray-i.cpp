/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double max_ = 0;
        if (nums.size() == 0)
            return max_;
        for (int i = 0; i < k; i++)
        {
            max_ += nums[i];
        }
        double pre_sum = max_;
        for (int i = 1; i <= nums.size() - k; i++)
        {
            pre_sum = pre_sum - nums[i - 1] + nums[i + (k - 1)];
            max_ = max(max_, pre_sum);
        }

        return (max_ / k);
    }
};
// @lc code=end
