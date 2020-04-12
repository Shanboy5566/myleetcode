/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution
{
public:
    /*

    Because the 'x' element not certainly exist in 'arr'
    
    Step1. we look for the index that 'first' smaller or equal than 'x'
    Step2. the index from step1. called 'left', and we can refer 'right' to 'left+1' represented the first larger or equal than 'x'
    Step3. check the difference between 'left' element and 'x' and difference between 'right' element and 'x'. if 'left' distance smaller than 'right', move 'left' to 'left--'


    */
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> ans;
        // Step 1
        int l = findSmallerOrEqual(arr, x);
        // cout << "first smaller or equal index: " << l << endl;
        // Step 2
        int r = l + 1;
        // Step 3
        while (k > 0)
        {
            // cout << "l: " << l << endl;
            // cout << "r: " << r << endl;
            if (l < 0)
                r++;
            else if (r >= arr.size())
                l--;
            else
            {
                if (x - arr[l] <= arr[r] - x)
                {
                    l--;
                }
                else
                {
                    r++;
                }
            }
            k--;
        }

        l++;
        r--;

        for (int i = l; i <= r; i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }

    int findSmallerOrEqual(vector<int> &arr, int x)
    {
        int l = 0, r = arr.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (arr[m] <= x)
                l = m + 1;
            else
                r = m - 1;
        }
        return r >= 0 ? r : 0;
    }
};
// @lc code=end
