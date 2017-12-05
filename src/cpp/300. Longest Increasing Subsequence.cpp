/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. 
Note that there may be more than one LIS combination, 
it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/
#include <common.hpp>
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> dp(n, 1);

        int res = 1;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                    dp[i] = std::max(dp[i], dp[j] + 1);
            }
            res = std::max(res, dp[i]);
        }
        return res;
    }
};

/*
solution 1
time:O(n^2)
space:O(n)
*/

#ifdef USE_GTEST
TEST(DSA, 300_LIS)
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution s;
    int res = s.lengthOfLIS(nums);
    ASSERT_TRUE(res == 4);
}
#endif