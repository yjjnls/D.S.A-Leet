/*

Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

Example 1:
Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
Note:
The n will be in the range [1, 1000].

*/

#include <common.hpp>
class Solution
{
public:
    int minSteps(int n)
    {
        vector<int> dp(n + 1, 0);

        for (int i = 2; i < n + 1; ++i)
        {
            dp[i] = i;//如果没有因子，那么就是copy i次1个A
            for (int j = i - 1; j > 1; --j)
            {
                //找出最大的因子，这样copy的step最小
                if (i % j == 0)
                {
                    dp[i] = dp[j] + i / j;
                    break;
                }
            }
        }

        return dp[n];//n个A
    }
};

/*
solution 1 dp

time:O(n^2)

------------------------------------
solution 2 recursion

if n % 2 == 0, then f(n) = f(n/2) + 2
if n % 3 == 0, then f(n) = f(n/3) + 3

if n % k == 0, then f(n) = f(n/k) + k  k<=n

time:O(log n) worst:O(n)
*/

class Solution2
{
public:
    int minSteps(int n)
    {
        //terminator
        if (n == 1)
            return 0;
        //current processing + drill down
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return i + minSteps(n / i);

        return n;
    }
};

#ifdef USE_GTEST
TEST(DSA, 650_2Key_keyboard)
{
    Solution s;
    int res = s.minSteps(3);
    ASSERT_TRUE(res == 3);

    int res2 = s.minSteps(1);
    ASSERT_TRUE(res2 == 0);
}
#endif