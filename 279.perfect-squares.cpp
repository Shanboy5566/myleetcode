/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        /*
        nums = [1, 4, 9, 16, ...], nums[i] = (i+1)^2
        dp[n] = (i=0~I, nums[I] < n)min(dp[n-nums[i]] + dp[nums[i]])
        which dp[nums[i]] = dp[(i+1)^2] = 1
        dp[n] = (i=0~I, nums[I] < n)min(dp[n-nums[i]] + 1)
        */

        // vector<int> dp(n, INT_MAX);
        int dp[n];

        for (int i = 0; i < n; i++){
            // cout << "i: " << i << endl;
            // int i_sqrt = sqrt(i+1);
            dp[i] = (i+1);
            // for (int k = 0; pow((k+1), 2) <= (i+1); k++){
            for (int k = 0; (k+1)*(k+1) <= (i+1); k++){
                // cout << "k: " << k << endl;
                // if (pow((k+1), 2) == (i+1)){
                if ((k+1)*(k+1) == (i+1)){
                    dp[i] = 1;
                    break;
                }
                // dp[i] = min(dp[i], dp[i-pow((k+1), 2)] + 1);
                dp[i] = min(dp[i], dp[i-(k+1)*(k+1)] + 1);
            }
        }

        return dp[n-1];


    }
};
// @lc code=end

