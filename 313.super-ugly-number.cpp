/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 */

// @lc code=start
/*

    min_history     0   1   2   3   4
    min_ugly        1   2   4   7   14

    history\primes  2   7   13  19
    step.0          0   0   0   0
    step.1          1   0   0   0
    step.2          2   0   0   0
    step.3          2   1   0   0

    step1.
        2   *   (min_ugly[history[0]]) = 2  * 1 = 2
        7   *   (min_ugly[history[1]]) = 7  * 1 = 7
        13  *   (min_ugly[history[2]]) = 13 * 1 = 13
        19  *   (min_ugly[history[3]]) = 19 * 1 = 19

        min         => 2
        min_ugly    => 2
        history[0]++ , next time when prime "2" multiply would multiply "min_ugly"

    step2.
        2   *   (min_ugly[history[0]]) = 2  * 2 = 4
        7   *   (min_ugly[history[1]]) = 7  * 1 = 7
        13  *   (min_ugly[history[2]]) = 13 * 1 = 13
        19  *   (min_ugly[history[3]]) = 19 * 1 = 19
        
        min         => 4
        min_ugly    => 4
        history[0]++ , next time when prime "2" multiply would multiply "min_ugly"

    step3.
        2   *   (min_ugly[history[0]]) = 2  * 4 = 8
        7   *   (min_ugly[history[1]]) = 7  * 1 = 7
        13  *   (min_ugly[history[2]]) = 13 * 1 = 13
        19  *   (min_ugly[history[3]]) = 19 * 1 = 19
        
        min         => 7
        min_ugly    => 7
        history[1]++ , next time when prime "7" multiply would multiply "min_ugly"

*/
 
class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    if (n == 1) return 1;
    vector<int> history(primes.size(), 0);
    vector<int> min_ugly(n, 0);

    min_ugly[0] = 1;
    int c = 1;

    while(c < n){
        int min_ = INT_MAX;
        int min_idx = -1;
        cout << "c: " << c << endl; // 
        for (int i = 0; i < primes.size(); i++){
            int prime = primes[i];
            int cost_ = prime * min_ugly[history[i]];
            if (cost_ < min_){
                min_ = cost_;
                min_idx = i;
            }
        }
        // cout << "min: " << min_ << endl;
        // cout << "min_idx: " << min_idx << endl;
        history[min_idx]++;
        // cout << "history of 2: " << history[0] << endl;
        // cout << "history of 7: " << history[1] << endl;
        // cout << "history of 13: " << history[2] << endl;
        // cout << "history of 19: " << history[3] << endl;
        if (min_ == min_ugly[c-1]) continue;
        min_ugly[c] = min_;
        c++;
        // cout << "====================\n";
    }
    return min_ugly[n-1];

  }
};
// @lc code=end

