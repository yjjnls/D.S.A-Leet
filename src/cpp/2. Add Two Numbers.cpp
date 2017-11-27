/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL && l2 == NULL)
        {
            return NULL;
        }

        ListNode result(0);
        ListNode *node = &result;
        int sum = 0;

        while (l1 != NULL || l2 != NULL || sum != 0)
        {
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            ListNode *next = new ListNode(sum % 10);
            sum /= 10;
            node->next = next;
            node = next;
        }
        return result.next;
    }
};

//O(N)

TEST(DSA, 2_Add_Two_Numbers)
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *result = new ListNode(7);
    result->next = new ListNode(0);
    result->next->next = new ListNode(8);

    ListNode *res = addTwoNumbers(l1, l2);
    while (res != NULL && result != NULL)
    {
        ASSERT_TRUE(res->val == result->val);
        res = res->next;
        result = result->next;
    }
    ASSERT_TRUE(res == NULL && result == NULL);

    free_list(l1);
    free_list(l2);
    free_list(result);
    free_list(res);
}