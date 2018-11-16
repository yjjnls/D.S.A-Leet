#ifndef _COMMON_HPP_
#define _COMMON_HPP_
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
ListNode *create_list(vector<int> nums);
void free_list(ListNode *l);
void compare_lists(ListNode *l1, ListNode *l2);

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
#endif