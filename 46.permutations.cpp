/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    
    void possible(vector<int>& nums, vector<int>& visited, unordered_set<int>& used){
        const int n = nums.size();
        if (visited.size() == n){
            ans.push_back(visited);
            return;
        }
        
        for (int i = 0; i < n; i++){
            
            if (used.find(nums[i]) != used.end()) continue;

            used.insert(nums[i]);
            visited.push_back(nums[i]);
            
            possible(nums, visited, used);
            
            visited.pop_back();
            used.erase(nums[i]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> used;
        vector<int> visited;
        possible(nums, visited, used);
        return ans;
    }
};
// @lc code=end

