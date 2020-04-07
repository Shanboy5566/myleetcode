/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    unordered_map <string, bool> memory;
    bool wordBreak(string s, vector<string>& wordDict) {
        // make HashSet for wordDict
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());

        // Helper
        return isWordBreak(s, dict);
    }

    bool isWordBreak(const string& s, const unordered_set<string>& dict){
        // In memory, return true immediately
        if (memory.count(s)) return memory[s];
        // Not seen but in dict
        if (dict.count(s)) {
            cout << "memorize 1: " << s << endl;
            memory[s] = true; // memorize
            return true;
        }
        // leetcode  dict = ["leetcode"]
        // split the word two part
        for (int i = 1; i < s.length(); i++){
            const string left = s.substr(0,i);
            const string right = s.substr(i);
            if (dict.count(left) && isWordBreak(right, dict)){
                memory[s] = true;
                return true;
            }
        }
        memory[s] = false;
        return false;
    }
};
// @lc code=end

