/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        /*
        find first min and check the (local max - min)
        */
        if (prices.empty())
            return 0;
        int min = prices[0], ans = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < min)
            {
                min = prices[i];
            }
            else
            {
                ans = max(ans, prices[i] - min);
            }
        }
        return ans;
    }
};
// @lc code=end
