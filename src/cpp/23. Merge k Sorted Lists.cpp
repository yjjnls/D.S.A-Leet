/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    struct compare
    {
        bool operator()(const ListNode *l, const ListNode *r)
        {
            if (l == NULL || r == NULL)
            {
                return false;
            }
            return l->val > r->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
        {
            return NULL;
        }
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        for (auto it : lists)
        {
            //这一句很重要
            if (it != NULL)
            {
                q.push(it);
            }
        }
        ListNode dummy(0);
        ListNode *result = &dummy;
        while (!q.empty())
        {
            if (result != NULL)
                result->next = q.top();
            result = result->next;
            q.pop();
            if (result != NULL && result->next != NULL)
            {
                q.push(result->next);
            }
        }
        return dummy.next;
    }
};

/*
solution 1
merge the list one by one, each process is a `merge 2 sorted lists` problem.
time:O(N^2)
*/

/*
solution 2
use priority_queue
time:O(Nklogk)
该方法可能比较耗内存
*/

/*
solution 3
divide and conquer
todo
*/
