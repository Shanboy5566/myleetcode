/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // binary search
        // (4, 5, 6, 7, 0, 1, 2)
        int ans = -1;
        int n = nums.size();
        if (n < 1){
            return -1;
        }else if (n == 0){
            if (target == nums[0]){
                return 0;
            }else{
                return -1;
            }
        }
        int left = 0, right = n - 1;
        // bool rotated = false;
        // if (nums[0] >= nums[n-1]){
        //     rotated = true;
        // }
        while(left <= right){ // [(4, 5, 6, 7), (8, 1, 2, 3)] find 8
            // [(8, 1, 2, 3), (4, 5, 6, 7)]
            
            // 0 1 2 3 4 5 6 7
            // 7 0 1 2 3 4 5 6
            // 6 7 0 1 2 3 4 5 
            // 5 6 7 0 1 2 3 4
            // 4 5 6 7 0 1 2 3
            // 3 4 5 6 7 0 1 2 
            // 2 3 4 5 6 7 0 1
            // 1 2 3 4 5 6 7 0
            
            // [4,5,6,7,8,1,2,3] find 8
            
            // cout << "left: " << left << endl;
            // cout << "right: " << right << endl;
            int middle = (left + right) / 2; // 
            // cout << "middle: " << middle << endl;
            if (nums[middle] == target){
                ans = middle;
                break; 
            }else if (nums[middle] < target){
                int middle_shift;
                if (middle + 1 > right){
                    middle_shift = right;
                }else{
                    middle_shift = middle + 1;
                }
                int area_min = min(nums[middle_shift], nums[right]);
                int area_max = max(nums[middle_shift], nums[right]);
                if (nums[middle_shift] > nums[right] || (area_min <= target && target <= area_max)){
                    left = middle + 1; // right area
                }else{
                    right = middle - 1;
                }
            }else if (nums[middle] > target){
                int middle_shift;
                if (middle - 1 < left){
                    middle_shift = left;
                }else{
                    middle_shift = middle - 1;
                }
                int area_min = min(nums[middle_shift], nums[left]);
                int area_max = max(nums[middle_shift], nums[left]);
                if (nums[middle_shift] < nums[left] || (area_min <= target && target <= area_max)){
                    right = middle - 1;
                }else{
                    left = middle + 1;
                }
            }
            // cout << "========\n";
        }
        return ans;
    }
};
// @lc code=end

