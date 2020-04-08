/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int n = prices.size();
        int s0[n+1], s1[n+1], s2[n+1];
        s0[0] = 0;
        s1[0] = INT_MIN;
        s2[0] = 0;
        for (int i = 1; i <= n; i++){
            int price = prices[i-1];
            // cout << i << endl;
            s0[i] = max(s2[i-1], s0[i-1]);
            s1[i] = max(s1[i-1], s0[i-1] - price);
            s2[i] = s1[i-1] + price;
        }
        int result = max(max(s0[n], s1[n]), s2[n]);
        return result;
    }
};
// @lc code=end

