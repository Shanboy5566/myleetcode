
/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        unordered_map<int, unordered_set<int>> path;
        queue<int> q;
        vector<int> ans;
        
        /* make map
            [[1, 0], [1, 2], [1, 3]]
            1. Read [1, 0] then update path 1 -> 0, 0 -> 1
        */
        for (auto edge : edges){
            path[edge[0]].insert(edge[1]);
            path[edge[1]].insert(edge[0]);
        }

        // In every iteration, BFS for each leaves
        
        // make queue
        for (int i = 0; i < n; i++){
            if (path[i].size() == 1){
                q.push(i);
            }
        }

        // 
        while(n > 2){ // ??
            int size = q.size();
            n -= size; 
            // BFS queue
            for (int i = 0; i < size; i++){
                // cout << "i: " << i << endl;
                int l = q.front(); 
                // remove edge
                for (auto node : path[l]){
                    path[node].erase(l);
                    if (path[node].size() == 1) q.push(node);
                }
                q.pop();
            } 
        }

        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;

    }
};
// @lc code=end

