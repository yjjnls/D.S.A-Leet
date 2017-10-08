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

#include <gtest/gtest.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
        : val(x), next(NULL)
    {
    }
    ~ListNode()
    {
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

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