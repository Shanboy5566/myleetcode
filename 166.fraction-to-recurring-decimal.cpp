/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
        if (numerator == 0) return "0";
        if (denominator == 0) return ans;
        
        long num = abs((long) numerator);
        long deno = abs((long) denominator);
        long remain = 0;
        unordered_map<long, int> map; // map the remainder to its index

        if (num % deno == 0){
            ans = to_string(num / deno);
        }else{
            ans = to_string(num / deno) + ".";
        }
        remain = num % deno;

        // cout << "num: " << num << endl;
        // cout << "deno: " << deno << endl;
        // cout << "remain: " << remain << endl;
        // if remainder != 0 and remainder not in map

        while( remain != 0 && map.find(remain) == map.end()){
            map[remain] = ans.length();
            remain *= 10;
            ans += to_string(remain / deno);
            remain = remain % deno;
        }

        // insert "(" and ")" if remainder != 0, remainder this time would be the start of "("
        if (remain != 0){
            ans.insert(map[remain], "(");
            ans.insert(ans.length(), ")");
        }

        if (numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0){
            return "-" + ans;
        }else{
            return ans;
        }
    }
};
// @lc code=end

