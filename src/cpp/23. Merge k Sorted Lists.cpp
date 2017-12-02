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
using std::priority_queue;
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

solution 2
手动比较每个链表的当前第一个节点，选一个最小的合并
time:O(Nk)

solution 3
use priority_queue
time:O(Nlogk) k个链表一共有N个结点
space:O(N) 主要分配priority_queue的内存
该方法可能比较耗内存


solution 4
divide and conquer
原理和solution 1一样，但是合并过程用分治
这里的分治的意思是每两个链表合并一次，合并之后产生的新链表再重复这样的操作
两个链表合并还是按照solution 2的逐个比较元素，时间复杂度为O(n)
k个链表，两两合并，最终的复杂度为O(logk)
time:O(NlogK)
space:O(1)
*/

class Solution4
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return NULL;

        while (lists.size() > 1)
        {
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    //可以用递归，也可以用迭代
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};


#ifdef USE_GTEST
TEST(DSA, 21_mergeTwoLists)
{
    ListNode *l1 = create_list(vector<int>{1, 3, 5, 7});
    ListNode *l2 = create_list(vector<int>{2, 4, 8});
    ListNode *l3 = create_list(vector<int>{6, 9, 10});
    vector<ListNode *> lists1 = {l1, l2, l3};
    ListNode *result = create_list(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

    Solution s1;
    ListNode *res = s1.mergeKLists(lists1);
    while (res != NULL && result != NULL)
    {
        ASSERT_TRUE(res->val == result->val);
        res = res->next;
        result = result->next;
    }
    ASSERT_TRUE(res == NULL && result == NULL);

    vector<ListNode *> lists2 = {l1, l2, l3};
    Solution4 s4;
    res = s4.mergeKLists(lists2);
    while (res != NULL && result != NULL)
    {
        ASSERT_TRUE(res->val == result->val);
        res = res->next;
        result = result->next;
    }
    ASSERT_TRUE(res == NULL && result == NULL);

    free_list(l1);
    free_list(l2);
    free_list(l3);
    free_list(result);
}
#endif