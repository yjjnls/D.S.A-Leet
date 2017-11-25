/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <common.hpp>
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode *cur = head;
        ListNode *next = cur->next;
        while (next != NULL)
        {
            if (cur->val == next->val)
            {
                cur->next = next->next;
                next = cur->next;
            }
            else
            {
                next = next->next;
                cur = cur->next;
            }
        }
        return head;
    }
};