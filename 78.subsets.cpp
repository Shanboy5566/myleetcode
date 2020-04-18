/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> current;
        ans.push_back(current);
        backtrack(nums, current, 0);
        return ans;
    }

    void backtrack(vector<int> &nums, vector<int> &current, int s)
    {
        for (int i = s; i < nums.size(); i++)
        {
            current.push_back(nums[i]);
            ans.push_back(current);
            backtrack(nums, current, i + 1);
            current.pop_back();
        }
    }
};
// @lc code=end
