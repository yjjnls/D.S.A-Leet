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
#ifdef USE_GTEST
TEST(DSA, 2_Add_Two_Numbers)
{
    ListNode *l1 = create_list(vector<int>{2, 4, 3});

    ListNode *l2 = create_list(vector<int>{5, 6, 4});

    ListNode *result = create_list(vector<int>{7, 0, 8});

    Solution s;
    ListNode *res = s.addTwoNumbers(l1, l2);
    compare_lists(res, result);

    free_list(l1);
    free_list(l2);
    free_list(result);
    free_list(res);
}
#endif