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
        return 0;
    }
};
/*
solution1
遍历数组，不断更新min，max和profit
但这样的方法并不是dp！！！！

solution2
二维dp
profit[day_index][hold] day_index:0,1,2...n-1 hold:0,1
最终输出profit[n-1][0] 
*/

#ifdef USE_GTEST
TEST(DSA, 121_Best_Time_to_Buy_and_Sell_Stock)
{
    vector<int> nums = {2, 7, 11, 15};
    Solution s1;
    vector<int> res = s1.twoSum(nums, 13);
    vector<int> result = {0, 2};
    for (int i = 0; i < 2; ++i)
        ASSERT_TRUE(res[i] == result[i]);
}
#endif