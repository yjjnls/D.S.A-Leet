/*

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

*/
#include <common.hpp>
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> res;
        for (int i = 0; i <= num; ++i)
        {
            int count = 0;
            int tmp = i;
            while (tmp != 0)
            {
                tmp = tmp & (tmp - 1);
                ++count;
            }
            res.push_back(count);
        }
        return res;
    }
};
/*
solution 1 bitwise
time:O(n*sizeof(int))
space:O(1)

solution 2 dp
去掉一位1后还有多少个1
dp[i]=dp[i&(i-1)]+1

*/



class Solution2
{
public:
    vector<int> countBits(int num)
    {
        vector<int> dp(num + 1, 0);

        for (int i = 1; i <= num; ++i)
        {
            dp[i] = dp[i & (i - 1)] + 1;
        }
        return dp;
    }
};

#ifdef USE_GTEST
TEST(DSA, 38_countBits)
{
    Solution s;
    vector<int> res = s.countBits(5);
    vector<int> result = {0, 1, 1, 2, 1, 2};
    for (int i = 0; i < 6; ++i)
        ASSERT_TRUE(res[i] == result[i]);
}
#endif