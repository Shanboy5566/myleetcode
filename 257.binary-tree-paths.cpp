/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return ans;

        TreeNode* head = root;
        string current = to_string(head->val); // initialize the current to head node val

        // if tree only has one head node
        if (head->left == nullptr && head->right == nullptr) ans.push_back(current);
        // if tree has left child, go dfs
        if (head->left != nullptr) dfs(head->left, current, ans);
        // if tree has right child, go dfs
        if (head->right != nullptr) dfs(head->right, current, ans);

        return ans;
    }

    void dfs(TreeNode* head, string current, vector<string>& ans){
        /*

        ans => want modify (reference)
        current => do not want modify (value)

            head    left    right   current   move
        1.  1       2       3       1       node(1) -> go dfs left
        2.  2       null    5       1->2    node(2) -> go dfs right
        3.  5       null    null    1->2->5 node(5) return, push current to ans
        4.  1       2       3       1       node(1) -> go right
        5.  

        */
        current += "->" + to_string(head->val);
        cout << "node: " << head->val << endl;
        cout << "current: " << current << endl;
        // reach the leaf
        if (head->left == nullptr && head->right == nullptr) {
            ans.push_back(current);
            return;
        }

        if (head->left != nullptr) dfs(head->left, current, ans);
        if (head->right != nullptr) dfs(head->right, current, ans);
    }

private:
    vector<string> ans;
};
// @lc code=end

