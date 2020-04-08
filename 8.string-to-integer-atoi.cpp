/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        string trim_chars = "\t\n\v\r ";
        str = str.erase(0, str.find_first_not_of(trim_chars));
        str = str.erase(str.find_last_not_of(trim_chars) + 1);
        int sign = 1;
        long ans = 0;
        int start = 0;
        if (str[start] == '+'){
                sign = 1;
                start++;
            }else if (str[start] == '-'){
                sign = -1;
                start++;
            }
        for (int i = start; i < str.length(); i++){
            // cout << "sign: " << sign << endl;
            // cout << "char: " << str[i] << endl;
            if (isdigit(str[i])){
                ans = ans * 10 + sign * (str[i] - '0');
                if (ans > INT_MAX){
                    return INT_MAX;
                }else if(ans < INT_MIN){
                    return INT_MIN;
                }
            }else{
                return ans;
            }   
        }
        return ans;
    }
};
// @lc code=end

