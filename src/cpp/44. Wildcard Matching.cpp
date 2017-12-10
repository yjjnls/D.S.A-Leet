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
namespace
{
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
                dp[0][j] = (p[j - 1] == '*') && dp[0][j - 1];

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
------------------------------------------------------------------------------
solution 2 optimized dp
use prev to denote dp[i-1][j-1]

time:O(mn)
space:O(n)
------------------------------------------------------------------------------
solution 3 greedy
两个指针i j分别指向s和p，遍历i
1.当前字符匹配s[i]=p[j]，++i ++j
2.当前p[j]为*，i和j都记录下来（i为s中匹配到*的位置，记为match；j为p中*的位置，记为star_index）， 只移动pattern，++j
    2.1 如果下一次s[i]=p[j]依然匹配，那么表示pattern中的上一个*匹配empty，这时进入第一种情况
    2.2 如果下一次s[i]!=p[j]不匹配，那么看pattern上一位是否为* 
        2.2.1 pattern上一位为*，表示前一位*匹配当前s[i]。表示s[i]匹配p[j-1](s[match]匹配p[star_index])
              !!!!!理论上此时只要i++就可以，进行下一轮匹配，但是可能出现一种异常就是下一轮匹配到了2.1，但实际上s[i]还在*匹配的序列里
              比如 "acbdbg" "a*bg" 匹配到s[2]是就和p[2]匹配了，但其实应该是s[4]和p[2]匹配，这是需要将j重置到star_index+1


If *s==*p or *p == ? which means this is a match, then goes to next element s++ p++.
If p=='*', this is also a match, but one or many chars may be available, so let us save this *'s position and the matched s position.
If not match, then we check if there is a * previously showed up,
if there is no *,  return false;
if there is an *,  we set current p to the next element of *, and set current s to the next saved s position.

time:O(n)
space:O(1)
*/

    class Solution2
    {
    public:
        bool isMatch(string s, string p)
        {
            int m = s.length();
            int n = p.length();
            if (n > 30000)
                return false;// the trick

            vector<bool> dp(n + 1, false);
            dp[0] = true;

            for (int j = 1; j < n + 1; ++j)
                dp[j] = (p[j - 1] == '*') && dp[j - 1];

            for (int i = 1; i < m + 1; ++i)
            {
                int prev = dp[0];
                dp[0] = false;
                for (int j = 1; j < n + 1; ++j)
                {
                    int temp = dp[j];//dp[i-1][j]
                    if (p[j - 1] != '*')
                        dp[j] = prev && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                    else
                        dp[j] = dp[j - 1] || temp;
                    prev = temp;//到了下一层，prev就会变成dp[i-1][j-1]
                }
            }
            return dp[n];
        }
    };

    class Solution3
    {
    public:
        bool isMatch(string s, string p)
        {
            int m = s.length(), n = p.length();
            int i = 0, j = 0, star_index = -1, match;
            while (i < m)
            {
                if (j < n && p[j] == '*')
                {
                    match = i;
                    star_index = j++;
                }
                else if (j < n && (s[i] == p[j] || p[j] == '?'))
                {
                    i++;
                    j++;
                }
                else if (star_index >= 0)
                {
                    i = ++match;
                    j = star_index + 1;
                }
                else
                    return false;
            }
            while (j < n && p[j] == '*')
                j++;
            return j == n;
        }
    };

#ifdef USE_GTEST
    TEST(DSA, 44_wildcard_Matching)
    {
        string s("absddfa");
        string p("a?s**f**");

        Solution2 s1;
        bool res = s1.isMatch(s, p);
        ASSERT_TRUE(res);
    }
#endif
}