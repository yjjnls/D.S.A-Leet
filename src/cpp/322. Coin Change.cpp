/*
You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up 
that amount. If that amount of money cannot be made up by any combination of the 
coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

*/
#include <common.hpp>
class Solution2
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;

        for (int i = 1; i < amount + 1; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (coins[j] <= i)
                {
                    dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
/*
solution 1 brute force
1个1 2个1 3个1 ……所有情况列出来
time：(amount^n)

------------------------------------------------------------------------
solution 2 bottom to up DP
min_number_of_coins[current_amount] current_ammount:0,1,2,...,amount

dp[i] = min( dp[i] , dp[i-coins[]]+1 )


output:特别要注意这个output
要注意这里dp[0]=0 假设最小的面值为x， 那么dp[s]=amount+1 0<s<x
如果amount正好能拆分成coins组合，那么dp[i]一定是能递推到dp[0]
否则最后递推会落到dp[s]上面，那么最后就是amount+1了
dp[amount] > amount ? -1 : dp[amount];

time:O(n*amount) 
space:O(amount) 

------------------------------------------------------------------------
solution 3 up to buttom DP
其实应该叫dfs，因为从上至下用的是递归 (类似于70题的第一种解法)
time:O(n) 
这里的n并不是amount！！！！而是有n种组合，具体可以参考该题solution里面的图（相比于solution1 剪枝了很多无效的情况）
space:O(amount)
这里n为amount

当amount和coins的值【都很大】时，该方法就合适了
比如[2,3,4] 6 适合用solution2
但如果是[2*10^9 3*10^9 4*10^9] 6*10^12 solution2就是time limit exceeted

------------------------------------------------------------------------
solution 4 bfs
参考该题solution里面的图，可以发现，dfs会把每一种方法都尝试一遍，但是这里其实相当于求一个到达amount的最短路径
用bfs一层一层找下去，找到的第一个解一定是最短路径，也就是min number of coin
time:O(1^k+2^k+...+n^k)->O(n^k)
time:O(n^k)
这里n为coins个数，k为搜索数的最低高度，比如[1,2,5] 10,k=2
当coins很小，但是amount很大（[1,2,5] 10000），该方法对内存的消耗太大，还是用solution2 的dp合适
*/


class Solution4
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;

        // vector<int> visited(amount+1,0);
        int number = 0;
        std::queue<int> q;
        q.push(amount);

        while (!q.empty())
        {
            int cur_size = q.size();
            ++number;
            for (int i = 0; i < cur_size; ++i)
            {
                int cur_amount = q.front();
                q.pop();

                for (int j = 0; j < coins.size(); ++j)
                {
                    if (coins[j] == cur_amount)
                    {
                        return number;
                    }
                    else if (coins[j] > cur_amount)
                    {
                        continue;
                    }
                    else
                    {
                        q.push(cur_amount - coins[j]);
                    }
                }
            }
        }

        return -1;
    }
};


#ifdef USE_GTEST
TEST(DSA, 322_coinChange)
{
    vector<int> nums = {1, 2, 5};
    Solution2 s;
    int res = s.coinChange(nums, 11);
    ASSERT_TRUE(res == 3);

    Solution4 s2;
    int res2 = s2.coinChange(nums, 11);
    ASSERT_TRUE(res2 == 3);
}
#endif