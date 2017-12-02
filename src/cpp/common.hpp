#include <climits>
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <functional>
#include <algorithm>

#ifdef USE_GTEST
#include <gtest/gtest.h>
#endif

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
        : val(x), next(NULL)
    {
    }
};
//这里参数不用引用是纯粹为了偷懒，因为gcc不能引用临时对象
inline ListNode *create_list(vector<int> nums)
{
    ListNode *res = NULL;
    ListNode *&node = res;
    for (int num : nums)
    {
        node = new ListNode(num);
        node = node->next;
    }

    return res;
}
inline void free_list(ListNode *l)
{
    while (l != NULL)
    {
        ListNode *tmp = l;
        l = l->next;
        delete tmp;
    }
}
inline void compare_lists(ListNode *l1, ListNode *l2)
{
    while (l1 != NULL && l2 != NULL)
    {
        ASSERT_TRUE(l1->val == l2->val);
        l1 = l1->next;
        l2 = l2->next;
    }
    ASSERT_TRUE(l1 == NULL && l2 == NULL);
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        : val(x), left(NULL), right(NULL)
    {
    }
    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
            left = NULL;
        }
        if (right != NULL)
        {
            delete right;
            right = NULL;
        }
    }
};