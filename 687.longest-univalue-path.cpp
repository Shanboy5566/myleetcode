/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
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
private:
    int max_count = 0;
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        TreeNode* head = root;
        findUniPath(head);
        return max_count;
    }
    /*
    step    head    left    right   l   r   max_count
    step1.  1       4       5
    step2.  4       4       4
    step3.  4       n       n       0   0
    step4.  4       n       n       0   0
    step5.  4       4       4       1   1   2
    step6.  5       n       5       0
    step7.  5       n       5       0
    step8.  5       n       n       0   0
    step9.  5       n       5       0   1   2
    */
    int findUniPath(TreeNode* head){
        std::ios::sync_with_stdio(false);
        if (!head) return 0;
        int l = findUniPath(head->left);
        int r = findUniPath(head->right);

        if (head->left && head->val == head->left->val) l++;
        else l = 0;
        if (head->right && head->val == head->right->val) r++;
        else r = 0;

        max_count = max(max_count, l+r);
        return max(l, r);
    }

};
// @lc code=end

