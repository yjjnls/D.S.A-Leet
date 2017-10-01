/*
Reverse a singly linked list.
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode *pre = head;
        ListNode *node = head->next;
        ListNode *next = NULL;
        pre->next = NULL;
        while (node != NULL)
        {
            next = node->next;
            node->next = pre;
            pre = node;
            node = next;
        }
        return pre;
    }
};

//O(N)