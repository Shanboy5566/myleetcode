/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    map<int, string> m;
    vector<string> ans;
    void addCombinations(string combinations, string digits){
        // string combinations = "";
        if (digits.length() == 0){
            ans.push_back(combinations);
        }
        char digit = digits[0];
        string letters = m[digit - '0'];
        for (auto letter : letters){// a b c
            /* 
            a-
                d
                e
                f
            b-
                d
                e
                f
            c-
                d
                e
                f
            */
            addCombinations(combinations + letter, digits.substr(1));
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0){
            return ans;
        }
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        addCombinations("", digits);
        return ans;
    }
};
// @lc code=end

