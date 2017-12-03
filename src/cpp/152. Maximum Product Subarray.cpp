/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/
#include <common.hpp>
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int n = nums.size();
        vector<vector<int>> max_product(n, vector<int>(2, 1));

        max_product[0][0] = max_product[0][1] = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; ++i)
        {
            //遍历第i个数时，正模的最大值，如果出现中断，那么就从nums[i]重新开始
            max_product[i][0] = std::max(nums[i] * (nums[i] >= 0 ? max_product[i - 1][0] : max_product[i - 1][1]), nums[i]);
            max_product[i][1] = std::min(nums[i] * (nums[i] >= 0 ? max_product[i - 1][1] : max_product[i - 1][0]), nums[i]);
            res = std::max(res, max_product[i][0]);
        }
        return res;
    }
};

/*
max_product[num_index][positive]
output:
max( max_product[][0] )

max_product表示第i个数时，乘积的模的最大值，后面一位表示符号
*/

#ifdef USE_GTEST
TEST(DSA, 152_maxProduct)
{
    vector<int> nums = {2, 3, -2, 4};
    Solution s;
    int res = s.maxProduct(nums);

    ASSERT_TRUE(res == 6);
}
#endif