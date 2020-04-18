/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        /*
        Time:   O(m*n)
        Space:  O(m*n)
        dp[0][j] = 1
        dp[i][0] = 1
        dp[i][j] = dp[i][j-1] + dp[i-1][j]
        */
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[n - 1][m - 1];
    }
};
// @lc code=end
