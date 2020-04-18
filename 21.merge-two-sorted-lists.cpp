/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;

        while (l1 != nullptr || l2 != nullptr)
        {
            // cout << "current: " << current->val << endl;
            // cout << "l1->val: " << l1->val << endl;
            // cout << "l2->val: " << l2->val << endl;
            if (l2 == nullptr)
            {
                current->next = l1;
                break;
            }
            else if (l1 == nullptr)
            {
                current->next = l2;
                break;
            }
            if (l1->val > l2->val)
            {
                current->next = l2;
                current = l2;
                l2 = l2->next;
            }
            else if (l1->val < l2->val)
            {
                current->next = l1;
                current = l1;
                l1 = l1->next;
            }
            else
            {
                current->next = l1;
                l1 = l1->next;
                current->next->next = l2;
                l2 = l2->next;
                current = current->next->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end
