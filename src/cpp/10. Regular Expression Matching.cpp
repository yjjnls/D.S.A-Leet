/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/
#include <common.hpp>
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (p.empty())
            return s.empty();

        bool first_match = !s.empty() &&
                           (s[0] == p[0] || p[0] == '.');

        if ((p.size() >= 2) && (p[1] == '*'))
            return (isMatch(s, p.substr(2)) ||
                    (first_match && isMatch(s.substr(1), p)));
        else
            return first_match && isMatch(s.substr(1), p.substr(1));
    }
};

/*
solution 1 recursion (dfs)
总体思想：逐个字符比较，然后将比较过的字符去掉，继续下一轮比较

1.如果pattern没有正则，那么就是text与pattern逐个字符比较
2.如果pattern的正则只有.，那么也是逐个字符比较，比较到.，就直接表示通过
3.patter的正则还含有*，则要进行两种比较（单个字符，或者两个字符）

1)比较第一位first_match
text[0]==pattern[0] || pattern[0]='.'

2)比较第二位，如果此时pattern长度大于等于2，且pattern[1]='*'
a)匹配0个 继续下一轮 isMatch(text[0:],pattern[2:])
b)匹配多个 first_match && isMatch(text[1:],pattern[0:])

否则，不满足带*的条件，那么就继续下一轮isMatch(text[1:],pattern[1:])

time:(2^n)
space:(2^n)

-----------------------------------------------------------------
solution 2 dp
dp[i][j] text[0...i-1] match pattern[0...j-1] ?
1<=i<=m 1<=j<=n

https://leetcode.com/problems/regular-expression-matching/discuss/

time:O(mn)
space:O(mn)
*/
class Solution2
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;
        for (int i = 1; i <= m; i++)
            dp[i][0] = false;
        // s为empty，p当前不为*肯定不匹配
        // 若为*，匹配多次也不行
        // 这里的*只能匹配0次，然后转接到dp[0][j-2]上
        for (int j = 1; j <= n; j++)
            dp[0][j] = j > 1 && '*' == p[j - 1] && dp[0][j - 2];

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j - 1] != '*')
                    dp[i][j] =
                        // 之前匹配
                        dp[i - 1][j - 1] &&
                        // 当前也匹配（s第i个字符 匹配 p第j个字符）
                        (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
                else
                    // 当前p[j-1]（第j个字符）为*
                    dp[i][j] =
                        //之前就匹配，*匹配0次（p第j和第j-1个字符就没用了）
                        dp[i][j - 2] ||
                        //s当前字符和p前一个一样，或者p前一个字符为.
                        (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && dp[i - 1][j];

        return dp[m][n];
    }
};

#ifdef USE_GTEST
TEST(DSA, 10_Regular_Expression_Matching)
{
    string s("aacfdaccd");
    string p("a*.fd*..*d");

    Solution2 s1;
    bool res = s1.isMatch(s,p);
    ASSERT_TRUE(res);
}
#endif