/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int pr_1 = (m - 1), pr_2 = (n - 1), pr_current = nums1.size() - 1;
        while (pr_current >= 0)
        {
            if (pr_1 < 0)
            {
                nums1[pr_current--] = nums2[pr_2--];
                // pr_2--;
                // pr_current--;
                continue;
            }
            else if (pr_2 < 0)
            {
                nums1[pr_current--] = nums1[pr_1--];
                // pr_1--;
                // pr_current--;
                continue;
            }
            else
            {
                if (nums1[pr_1] > nums2[pr_2])
                {
                    nums1[pr_current--] = nums1[pr_1--];
                    // pr_1--;
                }
                else
                {
                    nums1[pr_current--] = nums2[pr_2--];
                    // pr_2--;
                }
                // pr_current--;
            }
        }
    }
};
// @lc code=end
