/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).


*/
#include <common.hpp>
namespace
{
    class Solution
    {
    public:
        int maxProfit(vector<int> &prices)
        {
            if (prices.empty())
                return 0;
            int n = prices.size();
            vector<int> tmp(2, 0);
            vector<vector<int>> profit(n, tmp);

            //init border
            //这里的二维数组只需要初始化profit[0][]，而profit[][0]是无法一开始就确定的，因为这里hold=0有两种状态的叠加，如果依然把hold分为0，2两种状态那么那退化为121题
            profit[0][0] = 0;
            profit[0][1] = -prices[0];

            for (int i = 1; i < n; ++i)
            {
                //profit[i][0]表示今天没有持有股票
                //可能的状态就是1.今天卖了（profit[i - 1][1] + prices[i]，profit[i - 1][1]表示昨天持有）
                //2.今天没买，昨天也没买（profit[i - 1][0]）
                profit[i][0] = std::max(profit[i - 1][1] + prices[i], profit[i - 1][0]);
                //profit[i][1]今天持有股票
                //可能是昨天没有持有，但是今天买了，或者昨天就持有了
                profit[i][1] = std::max(profit[i - 1][0] - prices[i], profit[i - 1][1]);
            }
            return profit[n - 1][0];
        }
    };


/*
状态profit[day_index][hold] hold:0,1
注意这里的输出不是dp数组里最大的，而是要输出最后一天的max(profit[n-1][])即profit[n-1][0]
因为121题中只能买卖一次，所以一次交易后节结束了，而这题可以交易多次，要到最后一天才算结束
之前某天的最大值会通过状态转移方程传递到最后一天，所以还是【比较最后一天的几种情况的最大值既可以】
time:O(n)
space:O(n)
----------------------------------------------------------------------------------------------
其实这里的无限制的转换条件就是交易次数k>=(n/2)
简化的做法就是不断买进卖出，只要价格高于买进，那就卖出，然后继续买进
*/

#ifdef USE_GTEST
    TEST(DSA, 122_Best_Time_to_Buy_and_Sell_Stock_II)
    {
        vector<int> prices = {7, 1, 5, 3, 6, 4};
        Solution s;
        int res = s.maxProfit(prices);
        ASSERT_TRUE(res == 7);

        vector<int> prices_null;
        int res3 = s.maxProfit(prices_null);
        ASSERT_TRUE(res3 == 0);
    }
#endif
}