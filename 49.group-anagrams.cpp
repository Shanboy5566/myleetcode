/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const int n = strs.size();
        vector<vector<string>> ans;
        
        unordered_map<string, vector<string>> map;
        
        for (int i = 0; i < n; i++){
            string now = strs[i];
            sort(now.begin(), now.end());
            map[now].push_back(strs[i]);
        }
        
        for (auto element : map){
            ans.push_back(element.second);
        }
        
        // for (unordered_map<string, vector<string>>::iterator it = map.begin(); it != map.end(); ++it)
        // {
        //     ans.push_back(it->second);
        // }
        
        
        return ans;
    }
};
// @lc code=end

