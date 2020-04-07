/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        // 2^7
        // 2 * 2 * ... * 2
        // 2 * 2^6
        // 2 * 4^3
        // 2^2 * 4^2
        // 2^2 * 16^1
        
        // 2.1^3
        // pre      x       n
        // 1        2.1     3
        // 1*2.1    2.1     2
        // 1*2.1    2.1^2   1
        if (n == 0) return 1.0;
        if (n == 1 || x == 1 || x == 0) return x;
        

        if (n < 0) {
            if (n == INT_MIN){
                x *= x;
                n /= 2;
            }
            return 1 / myPow(x, -n);
        }
        
        double pre = 1;
        while(n > 1){
            int parity = n % 2;
            if (parity){ // odd 3 5 7 ...
                n--;
                pre *= x;
            }
            n /= 2;
            x *= x;
        }
        // cout << "pre: " << pre << endl;
        // cout << "x: " << x << endl;
        
        

        return pre * x;
        
    }
};
// @lc code=end

