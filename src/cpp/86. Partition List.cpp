/*
Given a linked list and a value x, 
partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//solution 2　👇
#include <common.hpp>
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode dummy(0), dummy2(0);
        ListNode *p1 = &dummy, *p2 = &dummy2;
        while (head != NULL)
        {
            if (head->val < x)
            {
                p1->next = head;
                p1 = p1->next;
            }
            else
            {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p2->next = NULL;
        p1->next = dummy2.next;
        return dummy.next;
    }
};

//solution 1 (two pass)
//use two vectors/lists/queues to store the nums < and >= x
//swap the node value of original list with two vectors
//time:O(N)
//space:O(N)

//solution 2 (one pass)
//still use the method in solution 1 but create two new lists and return the newly concated list
