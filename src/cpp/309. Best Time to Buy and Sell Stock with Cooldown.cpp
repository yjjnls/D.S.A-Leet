/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) 
with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
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
        vector<vector<int>> profit(n, vector<int>(3, 0));

        profit[0][0] = profit[0][2] = 0;
        profit[0][1] = -prices[0];

        for (int i = 1; i < n; ++i)
        {
            profit[i][0] = std::max(profit[i - 1][0], profit[i - 1][2]);
            profit[i][1] = std::max(profit[i - 1][1], profit[i - 1][0] - prices[i]);
            profit[i][2] = profit[i - 1][1] + prices[i];
        }
        return std::max(profit[n - 1][0], profit[n - 1][2]);
    }
};

/*
profit[day_index][state] state:0(not hold),1(hold),2(cool down)

time:O(n)
space:O(n)
*/

#ifdef USE_GTEST
TEST(DSA, 309_Best_Time_to_Buy_and_Sell_Stock_with_CoolDown)
{
    vector<int> nums = {1, 2, 3, 0, 2};
    Solution s;
    int res = s.maxProfit(nums);
    ASSERT_TRUE(res == 3);
}
#endif