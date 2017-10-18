/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *entry = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                while (fast != entry)
                {
                    fast = fast->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};

/*
快慢指针在第k步相遇，圆环长度为r
2k-k=nr
k=nr

第一个相遇点为s
k-s=m
s=nr-m=(n-1)r+r-m
这里取n=1,则得到
s=r-m
s是从head到entry的距离
m是s到k的距离，由于s和k都在环上，所以r-m极为k到s的距离，即fast指针再走到entry的距离

感觉是纯数学问题！
*/