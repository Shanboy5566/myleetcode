/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {

public:
    static bool sort_by_first (const vector<int>& v1, const vector<int>& v2){
        return v1[0] < v2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (intervals.size() <= 1) return intervals;
        
        // sort
        sort(intervals.begin(), intervals.end(), sort_by_first);

        // merge
        // [1, 3] [2, 6] [8, 10]
        for (auto& interval : intervals){
            int current_start = interval[0];
            int current_end = interval[1];
            if (ans.empty() || current_start > ans.back()[1]){
                ans.push_back({current_start, current_end});
            }else{
                ans.back()[1] = max(current_end, ans.back()[1]);
            }
        }

        return ans;
    }
};
// @lc code=end

