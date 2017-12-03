/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
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
            vector<vector<int>> tmp2(3, tmp);
            vector<vector<vector<int>>> profit(n, tmp2);

            //init border
            //初始化了xy平面
            profit[0][0][0] = 0;
            profit[0][0][1] = -prices[0];
            profit[0][1][0] = profit[0][1][1] = INT_MIN;
            profit[0][2][0] = profit[0][2][1] = INT_MIN;

            for (int i = 1; i < n; ++i)
            {
                //0 transactions, not hold
                profit[i][0][0] = profit[i - 1][0][0];//z方向的初始化border
                //0 transactions, hold
                profit[i][0][1] = std::max(profit[i - 1][0][1], hold_stock(profit[i - 1][0][0], prices[i]));

                //1 transactions, not hold
                profit[i][1][0] = std::max(profit[i - 1][1][0], profit[i - 1][0][1] + prices[i]);
                //1 transactions, hold
                profit[i][1][1] = std::max(profit[i - 1][1][1], hold_stock(profit[i - 1][1][0], prices[i]));

                //2 transactions, not hold
                profit[i][2][0] = std::max(profit[i - 1][2][0], profit[i - 1][1][1] + prices[i]);
            }
            return std::max(profit[n - 1][0][0], std::max(profit[n - 1][1][0], profit[n - 1][2][0]));
        }
        int hold_stock(int profit, int price)
        {
            if (profit < 0 && ((profit - INT_MIN) < price))
                return INT_MIN;
            return profit - price;
        }
    };


/*
status:
profit[day_index][transactions][hold] transactions:0,1,2 hold:0,1
output: 
profit[n-1][][0]

time:O(n)
space:O(6n)

这里用的是三维数组来进行dp，其实可以用几个变量来记录，将dp降为二维的，具体可以参考188题
*/

#ifdef USE_GTEST
    TEST(DSA, 123_Best_Time_to_Buy_and_Sell_Stock_III)
    {
        vector<int> prices = {7, 1, 5, 3, 6, 4};
        Solution s;
        int res = s.maxProfit(prices);

        ASSERT_TRUE(res == 7);
    }
#endif
}