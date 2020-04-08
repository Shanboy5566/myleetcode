/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ans = new ListNode(0);
        ListNode* current_ans = ans;
        
        while(l1 != NULL && l2 != NULL){
            current_ans->next = new ListNode(((l1->val + l2->val + carry) % 10));
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
            current_ans = current_ans->next;
        }
        while(l1 != NULL){
            current_ans->next = new ListNode(((l1->val + carry) % 10));
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
            current_ans = current_ans->next;
        }
        while(l2 != NULL){
            current_ans->next = new ListNode(((l2->val + carry) % 10));
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
            current_ans = current_ans->next;
        }
        if (carry != 0){
            current_ans->next = new ListNode(carry);
        }
        
        return ans->next;
    }
};
// @lc code=end

