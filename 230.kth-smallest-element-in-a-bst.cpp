/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
    int inorder (TreeNode* root, int& k){
        if (root == nullptr) return -1;
        int x = inorder(root->left, k);
        if (k == 0) return x;
        if (--k == 0) return root->val;
        return inorder(root->right, k);
    }
};

// @lc code=end

