/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, current);
        return ans;
    }

    void backtrack(vector<int> &candidates, int target, int s, vector<int> &current)
    {
        // cout << "n: " << n << endl;
        // if (!current.empty())
        // {
        //     cout << "[";
        //     for (auto e : current)
        //     {
        //         cout << to_string(e) + ", ";
        //     }
        //     cout << "]\n";
        // }
        if (target == 0)
        {
            ans.push_back(current);
            // cout << "====" << endl;
            return;
        }

        for (int i = s; i < candidates.size(); i++)
        {
            // cout << "i: " << i << endl;
            if (candidates[i] > target)
                break;
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, current);
            current.pop_back();
        }
    }
};
// @lc code=end
