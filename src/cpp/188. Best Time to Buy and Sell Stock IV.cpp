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

        if (k >= n / 2)
        {
            int maxPro = 0;
            for (int i = 1; i < n; i++)
            {
                if (prices[i] > prices[i - 1])
                    maxPro += (prices[i] - prices[i - 1]);
            }
            return maxPro;
        }
        vector<int> hold(2, 0);
        vector<vector<int>> transactions(k + 1, hold);
        vector<vector<vector<int>>> profit(n, transactions);

        //init border
        //init x-y and z-axis
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
                profit[i][j][1] = std::max(profit[i - 1][j][1], hold_stock(profit[i - 1][j][0], prices[i]));

                //j transactions, not hold
                profit[i][j + 1][0] = std::max(profit[i - 1][j + 1][0], profit[i - 1][j][1] + prices[i]);
            }
        }
        int res = 0;
        for (int i = 0; i < k + 1; ++i)
            res = std::max(res, profit[n - 1][i][0]);
        return res;
    }
    int hold_stock(int profit, int price)
    {
        if (profit < 0 && ((profit - INT_MIN) < price))
            return INT_MIN;
        return profit - price;
    }
};

/*
dp
status:
profit[day_index][transactions][hold] transaction:0,1,2,...,k hold:0,1

time:O(2*k*n)
space:O(2*k*n)

空间复杂度略高，当k和n很大时会超出内存分配范围！！！！
这里可以用变量来记录hold的情况，从而将三维dp降为二维dp
profit[day_index][transactions] 第i天交易了j次，且不持有股票的情况
用变量last_hold来表示 第i天交易了j次，且持有股票的情况，即last_hold = profit[i][j]-prices[i]

profit[i][j] = max( profit[i-1][j] , prices[i] + max(profit[m][j-1]-prices[m]) ) m<i
1.今天不交易，和昨天情况一样
2.今天交易了，卖出了股票，但买入价格是上一次交易之后的最低价，即last_hold最高

用profit[transactions][day_index]更容易理解

time:O(kn)
space:O(kn)
*/
class Solution2
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (prices.empty() || k < 1)
            return 0;
        int n = prices.size();
        //这个部分得要加，否则
        if (k >= n / 2)
        {
            int maxPro = 0;
            for (int i = 1; i < n; i++)
            {
                if (prices[i] > prices[i - 1])
                    maxPro += (prices[i] - prices[i - 1]);
            }
            return maxPro;
        }

        vector<int> day(n, 0);
        vector<vector<int>> profit(k + 1, day);

        //init border (ignored here)
        //profit[][0] = 0;
        //profit[0][] = 0;
        for (int i = 1; i < k + 1; ++i)
        {
            int last_hold = profit[i][0] - prices[0];
            for (int j = 1; j < n; ++j)
            {
                profit[i][j] = std::max(profit[i][j - 1], prices[j] + last_hold);
                last_hold = std::max(last_hold, profit[i - 1][j] - prices[j]);
            }
        }
        return profit[k][n - 1];
    }
};

#ifdef USE_GTEST
TEST(DSA, 188_Best_Time_to_Buy_and_Sell_Stock4)
{
    vector<int> prices1 = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
    Solution2 s;
    int res1 = s.maxProfit(4, prices1);
    ASSERT_TRUE(res1 == 15);
    int res2 = s.maxProfit(6, prices1);
    ASSERT_TRUE(res2 == 15);
}
#endif