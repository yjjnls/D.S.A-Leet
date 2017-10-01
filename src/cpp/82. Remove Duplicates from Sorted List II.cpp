/*
Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode **runner = &head;
        ListNode *scaner = NULL;
        while (*runner != NULL)
        {
            if ((*runner)->next != NULL &&
                (*runner)->val == (*runner)->next->val)
            {
                scaner = *runner;
                while (scaner != NULL && scaner->val == (*runner)->val)
                {
                    scaner = scaner->next;
                }
                *runner = scaner;
            }
            else
            {
                runner = &((*runner)->next);
            }
        }
        return head;
    }
};

//This problem may erase the head pointer of the list.
//get the ref of head to runner, so it could change the head as well


class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode *cur = &dummy;

        while (cur != NULL &&
               cur->next != NULL &&
               cur->next->next != NULL)
        {
            if (cur->next->val == cur->next->next->val)
            {
                int repeat = cur->next->val;
                ListNode *rm = cur->next->next;
                while (rm != NULL && rm->val == repeat)
                {
                    rm = rm->next;
                }
                cur->next = rm;
            }
            else
            {
                cur = cur->next;
            }
        }

        return dummy.next;
    }
};