/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 0){
            return "";
        }
        const int n = s.length();
        auto expandFromMiddel = [&](int left, int right){
            while(left >=0 && right < n && s[left] == s[right]){
                left--;
                right++;
            }
            return (right - 1) - (left + 1) + 1;
        };
        int start = 0, len = 0;
        for (int i = 0; i < n; i++){
            // len_1 = expandFromMiddel(s, i, i+1); // abba
            // len_2 = expandFromMiddel(s, i, i); // abvba
            int tmp = max(expandFromMiddel(i, i+1), expandFromMiddel(i, i));
            if (tmp > len){
                len = tmp;
                start = i - (tmp - 1) / 2;
                // end = i + (tmp) / 2;
            }
        }
        return (s.substr(start, len));
    }
};



// @lc code=end

