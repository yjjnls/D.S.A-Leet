/*
You are given coins of different denominations and a total amount of money. 
Write a function to compute the number of combinations that make up that amount. 
You may assume that you have infinite number of each kind of coin.

Note: You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1
*/
#include <common.hpp>
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        if (amount == 0)
            return 1;
        if (coins.empty())
            return 0;

        int n = coins.size();
        vector<int> dp(amount + 1, 0);

        dp[0] = 1;

        // 这里会把组合中的重复情况算进去，比如3-> 1+2 2+1重复计入
        // for (int i = 1; i < amount + 1; ++i)
        // {
        //     for (int j = 0; j < n; ++j)
        //     {
        //         if (coins[j] <= i)
        //             dp[i] += dp[i - coins[j]];
        //     }
        // }

        for (int i = 0; i < n; ++i)
        {
            for (int j = coins[i]; j < amount + 1; ++j)
            {
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp[amount];
    }
};

/*
参考322题
solution 1 dp
comb_num[amount]

dp[i] += dp[i-conis[]]

solution 2 dfs
遍历得到所有的组合
*/


#ifdef USE_GTEST
TEST(DSA, 518_coinChange2)
{
    vector<int> nums = {1, 2, 5};
    Solution s;
    int res = s.change(5, nums);
    ASSERT_TRUE(res == 4);
}
#endif