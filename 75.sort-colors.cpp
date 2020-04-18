/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        /*
        target = 1
        0~i             i~k     k~j         j~n-1
        small than 1    equal   non sort    larger
    */
        int n = nums.size(), i = 0, k = 0, j = n - 1;
        while (k <= j)
        {
            if (nums[k] < 1)
            {
                swap(nums[i++], nums[k++]);
            }
            else if (nums[k] > 1)
            {
                swap(nums[j--], nums[k]);
            }
            else
            {
                k++;
            }
        }
    }
};
// @lc code=end
