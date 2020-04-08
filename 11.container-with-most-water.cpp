/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() == 0){
            return 0;
        }
        int left = 0;
        int right = height.size() - 1;
        int water_max = 0;
        while(right - left != 0){
            water_max = max(water_max, (right-left)*(min(height[left], height[right])));
            if (height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return water_max;
    }
};
// @lc code=end

