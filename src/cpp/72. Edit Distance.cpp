/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
#include <common.hpp>
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i < m + 1; ++i)
            dp[i][0] = i;
        for (int j = 1; j < n + 1; ++j)
            dp[0][j] = j;

        for (int i = 1; i < m + 1; ++i)
        {
            for (int j = 1; j < n + 1; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = std::min(dp[i - 1][j], std::min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};
/*
solution1 dp

dp[i][j] word1(0,1,2,...,i-1)->word2(0,1,2,...,j-1)最小的距离 1<=i<=m  1<=j<=n(要确定参数的范围)

dp[i][0]=i
dp[0][j]=j

if word1[i-1][j-1]==word2[i-1][j-1]
    dp[i][j]=dp[i-1][j-1]
else
    dp[i][j]=min( dp[i-1][j], dp[i][j-1], dp[i-1][j-1] )+1

time:O(mn)
space:O(mn)


solution2 optimized dp
思路和221题一样，但是要注意的是221题中没有压缩时，不满足if条件时，dp=0；满足是dp=min()+1
而此题中不满足时dp=min()+1，而满足时，dp[i][j] = dp[i - 1][j - 1]; 而压缩后的dp[i - 1][j - 1]为prev！！！！

time:O(mn)
space:O(n)
*/

class Solution2
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i < n + 1; ++i)
            dp[i] = i;
        // int prev = 0;

        for (int i = 1; i < m + 1; ++i)
        {
            int prev = dp[0];//相当于dp[i-1][j-1] 这里是j-1=0的情况
            dp[0] = i;
            for (int j = 1; j < n + 1; ++j)
            {
                int temp = dp[j];
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[j] = prev;
                }
                else
                {
                    dp[j] = std::min(dp[j], std::min(dp[j - 1], prev)) + 1;
                }
                prev = temp;
            }
        }
        return dp[n];
    }
};
#ifdef USE_GTEST
TEST(DSA, 72_Edit_Distance)
{
    string word1("1237");
    string word2("5273");
    Solution s1;
    int res = s1.minDistance(word1, word2);
    ASSERT_TRUE(res == 3);
}
#endif