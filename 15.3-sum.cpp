/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() == 0){
            return ans;
        }
        int len = nums.size();
        // -1 0 1 2 -1 -4
        // sort -> (-4 -1 -1) (0 1 2) 
        sort(nums.begin(), nums.end()); //nlogn
        
        for (int i = 0; i < len - 2; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int l = i + 1; // =>  
            int r = len - 1; // <=
            if (nums[i] > 0) break; // *l *r positive, never 0
            // cout << "i: " << i << endl;
            // 0 0 0 0 1
            while(l < r){
                // cout << "l: " << l << endl;
                // cout << "r: " << r << endl;
                if (nums[i] + nums[l] + nums[r] == 0){
                    ans.push_back({nums[i], nums[l++], nums[r--]});
                    while(nums[l] == nums[l-1] && l < r) l++;
                    while(nums[r] == nums[r+1] && l < r) r--;
                }else if (nums[i] + nums[l] + nums[r] < 0){ // *l too small move =>
                    l++;
                }else{ // *r too large move <=
                    r--;
                }
            }
            // cout << "==========\n";
        }
        
        return ans;
    }
};
// @lc code=end

