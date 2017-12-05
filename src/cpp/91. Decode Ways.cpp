/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/
#include <common.hpp>
class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        if (n == 0 || s[0] == '0')
            return 0;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;//???
        for (int i = 1; i < n; ++i)
        {
            int curr = s[i] - '0';
            int prev = s[i - 1] - '0';

            if ((prev == 0 && curr == 0) || (curr == 0 && (prev * 10 + curr > 26)))
                return 0;
            else if (prev == 0 || (prev * 10 + curr) > 26)
                dp[i + 1] = dp[i];
            else if (curr == 0)
                dp[i + 1] = dp[i - 1];
            else
                dp[i + 1] = dp[i] + dp[i - 1];
        }
        return dp[n];
    }
};

/*

https://discuss.leetcode.com/topic/45327/java-2ms-dp-solution-with-detailed-explanation-and-inline-comments

dp[i]=dp[i-1]+dp[i-2]
这样要确定dp[0] dp[1]，但这里dp[1]无法确定，所以改换形式
dp[i+1]=dp[i]+dp[i-1]
最后输出dp[n]即可???


没想通为什么

*/

#ifdef USE_GTEST
TEST(DSA, 91_Decode_Ways)
{
    string s("7234721");
    Solution s1;
    int res = s1.numDecodings(s);
    ASSERT_TRUE(res == 4);

    string s2;
    int res2 = s.numDecodings(s2);
    ASSERT_TRUE(res2 == 0);
}
#endif