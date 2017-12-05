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
        if (n == 1)
            return 1;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;//?
        for (int i = 1; i < n; ++i)
        {
            int curr = dp[i] - '0';
            int prev = dp[i - 1] - '0';

            if (!isValid(s[i]) && !isValid(s[i - 1], s[i]))
                return 0;
            if (isValid(s[i]) && !isValid(s[i - 1], s[i]))
                dp[i + 1] = dp[i];
            if (!isValid(s[i]) && isValid(s[i - 1], s[i]))
                dp[i + 1] = dp[i - 1];
            if (isValid(s[i]) && isValid(s[i - 1], s[i]))
                dp[i + 1] = dp[i] + dp[i - 1];
        }
        return dp[n - 1];
    }
    bool isValid(char a, char b)
    {
        return a == '1' || (a == '2' && b <= '6');
    }
    bool isValid(char a)
    {
        return a != '0';
    }
};

/*

https://discuss.leetcode.com/topic/45327/java-2ms-dp-solution-with-detailed-explanation-and-inline-comments

dp[i]=dp[i-1]+dp[i-2]
这样要确定dp[0] dp[1]，但这里dp[1]无法确定，所以改换形式
dp[i+1]=dp[i]+dp[i-1]
最后输出dp[n-1]即可
*/