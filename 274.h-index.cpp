/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0, n = citations.size();
        // if (citations.empty()) return ans;
        sort(citations.begin(), citations.end());
        // make hash table
        // unordered_map <int, int> map;
        for (int i = 0; i < n; i++){
            int h = n - i;
            if (citations[i] < h) continue;
            else return ans = h;
            // else ans = max(ans, h);
        }
        return ans;
    }
};
// @lc code=end

