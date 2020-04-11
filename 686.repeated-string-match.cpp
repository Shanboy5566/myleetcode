/*
 * @lc app=leetcode id=686 lang=cpp
 *
 * [686] Repeated String Match
 */

// @lc code=start
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int a_size = A.length();
        int b_size = B.length();

        int times = b_size / a_size + 2; // wtf?

        string tmp = A;

        for (int i = 0; i < times; i++){
            if(tmp.find(B) != std::string::npos) return (i+1);
            tmp+=A;
        }

        return -1;
    }
};
// @lc code=end

