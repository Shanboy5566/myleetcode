/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        unordered_map<string, int> map;
        vector<TreeNode *> ans;
        getSubTreeId(root, map, ans);
        return ans;
    }

    string getSubTreeId(TreeNode *root, unordered_map<string, int> &map, vector<TreeNode *> &ans)
    {
        if (!root)
            return "*";

        string path = to_string(root->val) + getSubTreeId(root->left, map, ans) + getSubTreeId(root->right, map, ans);

        if (++map[path] == 2)
            ans.push_back(root);

        // if (map.count(path) > 0)
        // {
        //     if (map[path] == 1)
        //         ans.push_back(root);
        //     map[path]++;
        // }
        // else
        //     map[path] = 1;

        return path;
    }
};
// @lc code=end
