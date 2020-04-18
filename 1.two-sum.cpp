/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        /*
        brute-force:        O(N^2)
        Use binary-search:  O(NlogN)
        Use complement      O(N)
        */
        unordered_map<long, int> complement;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (complement.count(nums[i]) == 0)
            {
                complement[target - nums[i]] = i;
            }
            else
            {
                ans.push_back(complement[nums[i]]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
// @lc code=end
