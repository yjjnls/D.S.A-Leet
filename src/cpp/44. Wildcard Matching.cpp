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
    }
};
/*


*/

#ifndef USE_GTEST
TEST(DSA, 44_wildcard_Matching)
{
    string s("aacfdaccd");
    string p("a*.fd*..*d");

    Solution2 s1;
    bool res = s1.isMatch(s, p);
    ASSERT_TRUE(res);
}
#endif