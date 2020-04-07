/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;
        long range_start = nums[0]; //   0 -> 4 -> 7
        long range_end = nums[0]; //     0 -> 1 -> 2 -> 4 -> 5 ->7
        
        string tmp = "";
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] - range_end == 1){
                range_end = nums[i];
            }else{
                if (range_end == range_start) ans.push_back(to_string(range_end));
                else ans.push_back(to_string(range_start) + "->" + to_string(range_end));
                range_start = nums[i];
                range_end = nums[i];
            }
        }
        if (range_end == range_start) ans.push_back(to_string(range_end));
        else ans.push_back(to_string(range_start) + "->" + to_string(range_end));

        return ans;
    }
};
// @lc code=end

