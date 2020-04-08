/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        return is_bst(root, NULL, NULL);
    }
public:
    bool is_bst(TreeNode* node, TreeNode* node_min, TreeNode* node_max) {
        if (node == NULL){
            return true;
        }
        if ((node_min != NULL and node->val <= node_min->val) or (node_max != NULL and node->val >= node_max->val)){
            return false;
        }
        return is_bst(node->left, node_min, node) and is_bst(node->right, node, node_max);
    }
};
// @lc code=end

