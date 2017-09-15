/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }
        std::unordered_set<int> cache;
        for (ListNode *p = headA; p != NULL; p = p->next)
        {
            cache.insert(p->val);
        }
        for (ListNode *p = headB; p != NULL; p = p->next)
        {
            if (cache.find(p->val) != cache.end())
            {
                return p;
            }
        }
        return NULL;
    }
};

//time:O(N)
//space:O(N)

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }
        std::unordered_set<int> cache;
        for (ListNode *p = headA; p != NULL; p = p->next)
        {
            cache.insert(p->val);
        }
        for (ListNode *p = headB; p != NULL; p = p->next)
        {
            if (cache.find(p->val) != cache.end())
            {
                return p;
            }
        }
        return NULL;
    }
};

//solution2
/*
1.get length of two lists
2.if listB is longer, p2 move forward lenB-lenA
3.move p1 and p2, until get the same node or NULL

            p1
            👇
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
            👆
            p2
time:O(N)
space:O(1)
*/


//solution3
/*
connect A and B, B and A the same nodes will be the last several nodes
A->B : a1->a2->c1->c2->c3->b1->b2->b3->c1->c2->c3
B->A : b1->b2->b3->c1->c2->c3->a1->a2->c1->c2->c3
                                        👆  👆  👆
time:O(N)
space:O(1)
*/
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *cur1 = headA, *cur2 = headB;
        while (cur1 != cur2)
        {
            cur1 = cur1 ? cur1->next : headB;
            cur2 = cur2 ? cur2->next : headA;
        }
        return cur1;
    }
};


//What if the list has circle?