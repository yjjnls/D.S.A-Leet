/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/
#include <common.hpp>
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.length();
        int n = p.length();
        if (n > 30000)
            return false;// the trick

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int j = 1; j < n + 1; ++j)
            dp[0][j] = p[j - 1] == '*' && dp[0][j - 1];

        for (int i = 1; i < m + 1; ++i)
        {
            for (int j = 1; j < n + 1; ++j)
            {
                if (p[j - 1] != '*')
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                else
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
        }
        return dp[m][n];
    }
};
/*
solution 1 dp
if p[j - 1] != '*';
dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?')

if p[j - 1] == '*'.
dp[i][j] = dp[i][j - 1] || dp[i - 1][j]
dp[i][j - 1] * matches empty
dp[i - 1][j] * matches at least once

！！！！！！不容易判断
dp[i][0]=false
dp[0][j]
和第10题很类似，但第10题要判断j-2，所以要满足j>1，而这里并不需要
time:O(mn)
space:O(mn)

solution 2 optimized dp
use prev to denote dp[i-1][j-1]



*/

#ifndef USE_GTEST
TEST(DSA, 44_wildcard_Matching)
{
    string s("absddfa");
    string p("a?s**f**");

    Solution2 s1;
    bool res = s1.isMatch(s, p);
    ASSERT_TRUE(res);
}
#endif