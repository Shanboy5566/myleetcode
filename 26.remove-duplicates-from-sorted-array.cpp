/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return false;
        int n = nums.size();
        /*
        Array In-place => pop_back O(1)
        */

        int left = 0, right = 0;
        while (right < n)
        {
            if (nums[left] == nums[right])
                right++;
            else
            {
                left++;
                nums[left] = nums[right];
                right++;
            }
        }
        for (int i = (n - 1); i > left; i--)
        {
            nums.pop_back();
        }

        return left + 1;

        /*
        Erase not good, every time O(N)
        */
        // int count = 1, pre = nums[0];
        // nums.erase(nums.begin());
        // nums.push_back(pre);
        // for (int i = 1; i < n; i++)
        // {
        //     int now = *nums.begin();
        //     if (now != pre)
        //     {
        //         pre = now;
        //         nums.push_back(now);
        //         count++;
        //     }
        //     nums.erase(nums.begin());
        // }
        // return count;
    }
};
// @lc code=end
