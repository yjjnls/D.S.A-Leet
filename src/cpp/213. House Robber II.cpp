/*
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found 
himself a new place for his thievery so that he will not get too 
much attention. This time, all houses at this place are arranged 
in a circle. That means the first house is the neighbor of the 
last one. Meanwhile, the security system for these houses remain 
the same as for those in the previous street.

Given a list of non-negative integers representing the amount of 
money of each house, determine the maximum amount of money you 
can rob tonight without alerting the police.

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

#include <common.hpp>
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        
        vector<int> robber1(nums.begin(),nums.end()-1);
        vector<int> robber2(nums.begin()+1,nums.end());

        return std::max(rob_origin(robber1),rob_origin(robber2));

    }
    int rob_origin(vector<int> &nums)
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
time:O(n)
space:O(n)
*/


#ifdef USE_GTEST
TEST(DSA, 213_House_Robber2)
{
    vector<int> nums = {1, 3, 5, 2, 4, 6};
    Solution s;
    int res = s.rob(nums);
    ASSERT_TRUE(res == 11);

    vector<int> nums2 = {1};
    int res2 = s.rob(nums2);
    ASSERT_TRUE(res2 == 1);

    vector<int> nums3;
    int res3 = s.rob(nums3);
    ASSERT_TRUE(res3 == 0);
}
#endif