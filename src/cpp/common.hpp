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
};