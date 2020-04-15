/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
class Solution
{
public:
    // int depth = INT_MIN;
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        else
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        // dfs(root, 0);
        // return depth;
    }
    // void dfs(TreeNode *root, int d)
    // {
    //     if (!root)
    //         return;
    //     d++;
    //     depth = max(depth, d);
    //     dfs(root->left, d);
    //     dfs(root->right, d);
    // }
};
// @lc code=end
