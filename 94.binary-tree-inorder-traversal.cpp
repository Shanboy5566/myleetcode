/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL){
            return ans;
        }
        // traversal(root, ans);
        traversal_iter(root, ans);
        return ans;
    }
// public:
//     void traversal(TreeNode* root, vector<int> &ans){
//         if (root->left != NULL){
//             traversal(root->left, ans);
//         }
//         ans.push_back(root->val);
//         if (root->right != NULL){
//             traversal(root->right, ans);
//         }
//     }
public:
    void traversal_iter(TreeNode* root, vector<int> &ans){
        stack<TreeNode*> s;
        TreeNode* current = root;
        while(current != NULL || !s.empty()){
            while(current!=NULL){
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            ans.push_back(current->val);
            current = current->right;
        }
    }
};
// @lc code=end

