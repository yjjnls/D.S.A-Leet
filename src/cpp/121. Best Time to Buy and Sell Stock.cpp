/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.

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
        vector<int> tmp(3, 0);
        vector<vector<int>> profit(n, tmp);
        int res = 0;

        //init border
        profit[0][0] = profit[0][2] = 0;
        profit[0][1] = -prices[0];

        for (int i = 1; i < n; ++i)
        {
            profit[i][0] = profit[i - 1][0];
            //buy or buyed
            profit[i][1] = std::max(profit[i - 1][0] - prices[i], profit[i - 1][1]);
            //sell or sold
            profit[i][2] = std::max(profit[i - 1][1] + prices[i], profit[i - 1][2]);
            res = std::max(res, std::max(profit[i][0], std::max(profit[i][1], profit[i][2])));
        }
        return res;
    }
};
/*
solution1
遍历数组，不断更新min，max和profit
但这样的方法并不是dp！！！！

solution2
二维dp
profit[day_index][hold] day_index:0,1,2...n-1 hold:0(not hold),1(hold)，2(sold)
最终输出profit[n-1][0] 
*/

#ifdef USE_GTEST
TEST(DSA, 121_Best_Time_to_Buy_and_Sell_Stock)
{
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    vector<int> prices2 = {7, 6, 4, 3, 1};
    Solution s;
    int res1 = s.maxProfit(prices1);
    ASSERT_TRUE(res1 == 5);
    int res2 = s.maxProfit(prices2);
    ASSERT_TRUE(res1 == 0);
}
#endif