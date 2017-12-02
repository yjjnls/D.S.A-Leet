/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
*/
#include <common.hpp>
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

/*
上述solution是递归版的dp，可以说是从上往下
方法是对的，但是n大了之后time limit exceeded

迭代版的dp都是从下往上的
*/

class Solution2
{
public:
    int climbStairs(int n)
    {
        vector<int> step(n + 1, 0);
        if (n <= 0 || n == 1)
            return 1;

        //边界（起始）
        step[0] = 1;
        step[1] = 1;
        for (int i = 2; i < n + 1; ++i)
            step[i] = step[i - 1] + step[i - 2];

        return step[n];
    }
};

#ifdef USE_GTEST
TEST(DSA, 70_climbStairs)
{
    Solution2 s;
    int res1 = s.climbStairs(44);
    ASSERT_TRUE(res1 == 1134903170);
    int res2 = s.climbStairs(1);
    ASSERT_TRUE(res2 == 1);
}
#endif