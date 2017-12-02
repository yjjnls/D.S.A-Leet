/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
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
        vector<vector<int>> tmp2(3, tmp);
        vector<vector<vector<int>>> profit(n, tmp2);

        //init border
        profit[0][0][0] = 0;
        profit[0][0][1] = -prices[0];
        profit[0][1][0] = profit[0][1][1] = INT_MIN;
        profit[0][2][0] = profit[0][2][1] = INT_MIN;

        for (int i = 1; i < n; ++i)
        {
            //0 transactions, not hold
            profit[i][0][0] = profit[i - 1][0][0];
            //0 transactions, hold
            profit[i][0][1] = std::max(profit[i - 1][0][1], profit[i - 1][0][0] == INT_MIN ? INT_MIN : profit[i - 1][0][0] - prices[i]);

            //1 transactions, not hold
            profit[i][1][0] = std::max(profit[i - 1][1][0], profit[i - 1][0][1] + prices[i]);
            //1 transactions, hold
            profit[i][1][1] = std::max(profit[i - 1][1][1], profit[i - 1][1][0] == INT_MIN ? INT_MIN : profit[i - 1][1][0] - prices[i]);

            //2 transactions, not hold
            profit[i][2][0] = std::max(profit[i - 1][2][0], profit[i - 1][1][1] + prices[i]);
        }
        return std::max(profit[n - 1][0][0], std::max(profit[n - 1][1][0], profit[n - 1][2][0]));
    }
};

/*
status:
profit[day_index][transactions][hold] transactions:0,1,2 hold:0,1
output: 
profit[n-1][][0]

time:O(n)
*/

#ifdef USE_GTEST
TEST(DSA, 123_Best_Time_to_Buy_and_Sell_Stock3)
{
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    Solution s;
    int res1 = s.maxProfit(prices1);
    ASSERT_TRUE(res1 == 7);
}
#endif