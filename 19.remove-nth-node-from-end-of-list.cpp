/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if (head == NULL || head->next == NULL){
            return NULL;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < n; i++){
            fast = fast->next;
        }
        
        if (fast != NULL){
            while(fast->next != NULL){
                slow = slow->next;
                fast = fast->next;
            }
            slow->next = slow->next->next;
        }else{
            head = slow->next;
        }
        
        return head;
    }
};
// @lc code=end

