/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == ""){
            return 0;
        }
        else if (s.size() == 1){
            return 1;
        }
        set<int> uniq;
        int i = 0, j = 0;
        set<int>::iterator it;
        int ans = 0;
        while(j < s.size()){
            // cout << "i: " << i << "\n";
            // cout << "j: " << j << "\n";
            if (uniq.find(s[j]) == uniq.end()){
                // cout << "uniq insert: " << s[j] << "\n";
                uniq.insert(s[j]);
                j++;
                ans = max(ans, (j-i));
                // cout << "ans: " << ans << "\n";
            }
            else{
                // cout << "uniq erase: " << s[j] << "\n";
                uniq.erase(uniq.find(s[j]));
                i = i + s.substr(i, (j-i)).find(s[j]) + 1;
            }
            // cout << "-------\n";
        }
        return ans;
    }
};
// @lc code=end

