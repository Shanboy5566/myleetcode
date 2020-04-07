/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 */

// @lc code=start
class Solution {
public:
    int superEggDrop(int K, int N) {
        // dp[K][N] = 1 + (s=1~N)min[max(dp[K][N-S], dp[K-1][s-1])]
        ios_base::sync_with_stdio(false);
        vector<vector<int>> dp(K+1, vector<int>(N+1, 0));

        for (int k = 0; k <= K; k++){
            for (int n = 0; n <= N; n++){
                if (k == 0){
                    dp[k][n] = 0;
                    continue;
                }
                if (k == 1 || (k > 1 && n <= 1)){
                    dp[k][n] = n;
                    continue;
                }
                int min_move = INT_MAX;

                // find every max possible O(K*N^2)
                // for (int s = 1; s <= n; s++){
                    // min_move = min(min_move, max(dp[k][n-s], dp[k-1][s-1]));
                // }


                // binary search O(K*N*logN)
                int l = 1, r = n;
                while(l < r){
                    int m = l + (r - l) / 2;
                    if (dp[k-1][m-1] < dp[k][n-m]) l = m + 1;
                    else r = m;
                }
                min_move = min(min_move, max(dp[k][n-r], dp[k-1][r-1]));
                dp[k][n] = 1 + min_move;
                // cout << "min_move: " << (min_move + 1) << endl;
                // cout << "++++\n";

            }
        }

        return dp[K][N];
    }
};
// @lc code=end

