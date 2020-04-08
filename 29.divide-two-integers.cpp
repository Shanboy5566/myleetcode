/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        int ans = 0;
        long dividend_ = dividend;
        if ((dividend_ < 0 && divisor > 0) || (dividend_ > 0 && divisor < 0) ){
            sign = -1;
        }
        
        dividend_ = abs(dividend_);
        divisor = abs(divisor);
        
        if (dividend_ < divisor) return 0;
        
        if (divisor == 1){
            if (sign == 1){
                if (dividend_ >= INT_MAX){
                    return INT_MAX;
                }else{
                    return sign * dividend_;
                }
            }else{
                if (dividend == INT_MIN){
                    return INT_MIN;
                }else{
                    return sign * dividend_;
                }
            }
        }
        
        long tmp = divisor;
        while (dividend_ >= divisor){
            long res = tmp;
            int mul = 1;
            while(tmp + tmp <= dividend_){
                // cout << "tmp: " << tmp << endl;
                mul += mul;
                // cout << "mul: " << mul << endl;
                tmp += tmp;
                res = tmp;
                // cout << "------\n";
            }
            dividend_ -= res;
            tmp = divisor;
            ans += mul;
            // cout << "dividend: " << dividend_ << endl;
            // cout << "new tmp: " << tmp << endl;
            // cout << "======\n";
        }
        return sign * ans;
    }
};
// @lc code=end

