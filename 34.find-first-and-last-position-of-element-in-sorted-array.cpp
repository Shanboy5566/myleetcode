/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findStart(vector<int>& nums, int& target){
        int i = -1;
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
            if (nums[mid] == target) i = mid;
        }
        return i;
    }
    
    int findEnd(vector<int>& nums, int& target){
        int i = -1;
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
            if (nums[mid] == target) i = mid;
        }
        
        return i;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        const int n = nums.size();
        if (n <= 0){
            return {-1, -1};
        }
        int start, end;
        start = findStart(nums, target);
        end = findEnd(nums, target);
        return {start, end};
//         int left = 0;
//         int right = n - 1;
//         int mid;
//         int hit = -1;
//         // vector<int> ans;

//         while(left <= right){
//             mid = (left + right) / 2;
//             if (nums[mid] == target){
//                 hit = mid;
//                 // cout << "hit: " << hit << endl;
//                 break;
//             }else if(nums[mid] > target){
//                 right = mid - 1;
//             }else{
//                 left = mid + 1;
//             }
//         }
        
//         int p = hit;
//         int start = hit, end = hit;
//         if (hit == -1){
//             return {-1, -1};
//         }else{
//             while ((--p) >= 0 && nums[p] == target) start = p;
//             // cout << "start: " << start << endl;
//             p = hit;
//             while ((++p) < n && nums[p] == target) end = p;
//             // cout << "end: " << end << endl;
//         }
//         return {start, end};
        
        
    }
};
// @lc code=end

