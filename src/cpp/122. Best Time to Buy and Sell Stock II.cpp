/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).


*/
#include <common.hpp>
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
注意这里的输出不是dp数组里最大的，而是要输出最后一天的
因为121题中只能买卖一次，所以一次交易后节结束了，而这题可以交易多次，要到最后一天才算结束
time:O(n)
*/

#ifdef USE_GTEST
TEST(DSA, 122_Best_Time_to_Buy_and_Sell_Stock2)
{
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    Solution s;
    int res1 = s.maxProfit(prices1);
    ASSERT_TRUE(res1 == 7);
}
#endif