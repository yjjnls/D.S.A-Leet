/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverseList(slow->next);
        while (slow != NULL)
        {
            if (head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = NULL;
        ListNode *next = NULL;
        while (head != NULL)
        {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};

/*
1.reach the middle of the list
there is n elements in the list, when the fast pointer stops

slow = (n+1)/2      n is odd
    1->2->3->2->1->NULL
          👆       👆
          slow     fast
slow = n/2          n is even
    1->2->2->1->NULL
       👆 👆
       slow fast

2. reverse the rest half list from slow->next, slow points to 
    1->2->3->NULL
    👆 
    slow 

    1->2->NULL
    👆
    slow

3. compare slow and head, util slow is null
*/