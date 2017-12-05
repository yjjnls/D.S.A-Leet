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
solution 1 dp
time:O(n^2)
space:O(n)
nums[j] < nums[i]是说明当前的数字i可以作为序列j的后续
找出所有序列j，求max即为dp[i]
如果i之前的数字都比i大，那么dp[i]就是默认值1

solution 2 dp with binary search
dp数组不再是LIS的长度，而直接是LIS的数据

1.遍历原数组，dp为LIS数据（和nums一样长）
2.如果nums[i]大于dp中最大的数（最后一个），将nums[i]插入dp
3.否则在dp中找到第一个大于nums[i]的数，其位置为pos，将dp[pos]替换为nums[i]

这样最终dp为数字最小的LIS
10, 9, 2, 5, 3, 7, 101, 18

10 
9
2
2,5
2,3
2,3,7
2,3,7,101
2,3,7,18

time:O(nlogn)
space:O(n)

*/

class Solution2
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end())
                res.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return res.size();
    }
};
#ifdef USE_GTEST
TEST(DSA, 300_LIS)
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution s;
    int res = s.lengthOfLIS(nums);
    ASSERT_TRUE(res == 4);
}
#endif