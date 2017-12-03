/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

#include <common.hpp>
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (prices.empty() || k < 1)
            return 0;
        int n = prices.size();
        vector<int> hold(2, 0);
        vector<vector<int>> transactions(k + 1, hold);
        vector<vector<vector<int>>> profit(n, transactions);

        //init border
        profit[0][0][0] = 0;
        profit[0][0][1] = -prices[0];
        for (int i = 1; i < k + 1; ++i)
            profit[0][i][0] = profit[0][i][1] = INT_MIN;

        for (int i = 1; i < n; ++i)
        {
            //0 transactions, not hold
            profit[i][0][0] = profit[i - 1][0][0];

            for (int j = 0; j < k; ++j)
            {
                //j transactions, hold
                profit[i][j][1] = std::max(profit[i - 1][j][1], profit[i - 1][j][0] == INT_MIN ? INT_MIN : profit[i - 1][j][0] - prices[i]);

                //j transactions, not hold
                profit[i][j + 1][0] = std::max(profit[i - 1][j + 1][0], profit[i - 1][j][1] + prices[i]);
            }
        }
        int res = 0;
        for (int i = 0; i < k + 1; ++i)
            res = std::max(res, profit[n - 1][i][0]);
        return res;
    }
};

/*
dp
status:
profit[day_index][transactions][hold] transaction:0,1,2,...,k hold:0,1
*/
