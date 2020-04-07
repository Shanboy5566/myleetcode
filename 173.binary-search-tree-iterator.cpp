/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator {
public:

    stack<int> bst;

    void makeStack(TreeNode* current){
        if (current != NULL){
            makeStack(current->right); // R
            bst.push(current->val); // V
            makeStack(current->left); // L
        }
    }

    BSTIterator(TreeNode* root) {
        TreeNode* head = root;
        ios_base::sync_with_stdio(false); // ??
        makeStack(head);
    }
    
    /** @return the next smallest number */
    int next() { 
        int small_val = bst.top();
        bst.pop();
        return small_val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return bst.size() != 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

