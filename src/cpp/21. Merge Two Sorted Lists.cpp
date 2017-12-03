/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(INT_MIN);
        ListNode *node = &dummy;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                node->next = l1;
                l1 = l1->next;
            }
            else
            {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        node->next = l1 == NULL ? l2 : l1;
        return dummy.next;
    }
};
//time:O(N)
//space:O(1)


#ifdef USE_GTEST
TEST(DSA, 21_mergeTwoLists)
{
    ListNode *l1 = create_list(vector<int>{1, 3, 5});

    ListNode *l2 = create_list(vector<int>{2, 4, 6});

    ListNode *result = create_list(vector<int>{1, 2, 3, 4, 5, 6});

    Solution s;
    ListNode *res = s.mergeTwoLists(l1, l2);
    compare_lists(res, result);

    // free_list(l1);
    // free_list(l2);
    free_list(res);
    free_list(result);
}
#endif