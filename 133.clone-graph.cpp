/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if (node == NULL) return NULL;

        // BFS
        queue<Node*> visited;
        unordered_map<Node*, Node*> clone_map;

        visited.push(node); // head node
        Node* clone = new Node(node->val);
        clone_map[node] = clone; // 

        while(!visited.empty()){
            Node* old_visit = visited.front();
            visited.pop();
            for (auto neibor : old_visit->neighbors){
                if (clone_map.count(neibor) == 0){ // unseen
                    clone_map[neibor] = new Node(neibor->val); // make val clone
                    visited.push(neibor); // add queue
                }
                // make neighbor clone
                clone_map[old_visit]->neighbors.push_back(clone_map[neibor]);
            }
        }
        return clone;
        // map the relationship
    }
};
// @lc code=end

