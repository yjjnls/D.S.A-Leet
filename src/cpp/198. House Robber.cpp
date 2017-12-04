/*
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed, the only constraint 
stopping you from robbing each of them is that adjacent houses have 
security system connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money 
of each house, determine the maximum amount of money you can rob tonight 
without alerting the police.

Credits:
Special thanks to @ifanchu for adding this problem and creating all 
test cases. Also thanks to @ts for adding additional test cases.
*/

#include <common.hpp>
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0] = 0;
        dp[0][1] = nums[0];

        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }

        return std::max(dp[n - 1][0], dp[n - 1][1]);
    }
};

/*
solution 1 dp
money[house_index][robber] robber:0(not rob),1 (rob)

money[i][0] = max(money[i-1][0],money[i-1][1])
money[i][1] = money[i-1][0]+prices[i]

time:O(n)
space:O(n)
*/

#ifdef USE_GTEST
TEST(DSA, 198_House_Robber)
{
    vector<int> nums = {1, 3, 5, 2, 4, 6};
    Solution s;
    int res = s.rob(nums);

    ASSERT_TRUE(res == 12);
}
#endif