/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start

class UnionFindSet {
public:
    UnionFindSet(int n) {
        ranks_ = vector<int>(n + 1, 0);        
        parents_ = vector<int>(n + 1, 0);                
        
        for (int i = 0; i < parents_.size(); ++i)
            parents_[i] = i;
    }
    
    // Merge sets that contains u and v.
    // Return true if merged, false if u and v are already in one set.
    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) return false;
        
        // Meger low rank tree into high rank tree
        if (ranks_[pv] > ranks_[pu])
            parents_[pu] = pv;           
        else if (ranks_[pu] > ranks_[pv])
            parents_[pv] = pu;
        else {
            parents_[pv] = pu;
            ranks_[pv] += 1;
        }
        
        return true;
    }
    
    // Get the root of u.
    int Find(int u) {        
        // Compress the path during traversal
        if (u != parents_[u])
            parents_[u] = Find(parents_[u]);        
        return parents_[u];
    }
private:
    vector<int> parents_;
    vector<int> ranks_;
};
 
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {    
        UnionFindSet s(edges.size());
        
        for(const auto& edge: edges)
            if (!s.Union(edge[0], edge[1]))
                return edge;
        
        return {};
    }
};

// class Solution {
// public:
//     /*

//     1. Build the empty graph, called 'new'
//     2. Insert the 'u' to the new graph
//     3. Check the 'v' has the path to u. If so, return this edge

//     */
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         std::ios::sync_with_stdio(false);
//         unordered_map<int, vector<int>> graph;
//         for (auto edge : edges){ // O(N*N)
//             int u = edge[0];
//             int v = edge[1];
//             unordered_set<int> visited;
//             if (has_path(u, v, graph, visited)) return edge; // DFS
//             graph[u].push_back(v);
//             graph[v].push_back(u);
//             // cout << "========\n";
//         }
//         return {};
//     }

//     bool has_path(int u, int v, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited){
//         // cout << "u: " << u << endl;
//         // cout << "v: " << v << endl;
//         std::ios::sync_with_stdio(false);
//         if (u == v) return true;
//         visited.insert(u);
//         for (int node : graph[u]){
//             // cout << "node: " << node << endl;
//             if (visited.count(node)) continue;
//             if (has_path(node, v, graph, visited)) return true;
//         }
//         return false;
//     }
// };
// @lc code=end

