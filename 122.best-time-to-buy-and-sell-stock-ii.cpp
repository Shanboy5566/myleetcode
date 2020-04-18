/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        /*
        with[i]     => max(with[i-1], without[i-1]-price[i])
        without[i]  => max(without[i-1], with[i-1]+price[i])
        */
        // int with_stock_best = INT_MIN, without_stock_best = 0;
        int without_stock_best = 0, with_stock_best = INT_MIN;
        for (auto price : prices)
        {
            without_stock_best = max(without_stock_best, with_stock_best + price);
            with_stock_best = max(with_stock_best, without_stock_best - price);
            // without_stock_best = max(without_stock_best, with_stock_best + price);
        }
        return without_stock_best;
    }
};
// @lc code=end
