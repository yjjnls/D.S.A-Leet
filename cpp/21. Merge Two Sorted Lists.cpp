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