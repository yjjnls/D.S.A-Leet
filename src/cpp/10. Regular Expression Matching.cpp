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
        return false;
    }
};



#ifndef USE_GTEST
TEST(DSA, 10_Regular_Expression_Matching)
{
    string s("7234721");
    Solution s;
    int res = s.numDecodings(s);
    ASSERT_TRUE(res == 4);

    string s2;
    int res2 = s.numDecodings(s2);
    ASSERT_TRUE(res2 == 0);
}
#endif