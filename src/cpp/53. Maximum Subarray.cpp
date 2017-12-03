/*
Find the contiguous subarray within an array (containing at least one number)
which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the
divide and conquer approach, which is more subtle.
*/
#include <common.hpp>
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curr_sum = 0, max_sum = nums[0];
        for (int i = 0; i < nums.size(); ++i)
        {
            curr_sum = std::max(nums[i], curr_sum + nums[i]);
            max_sum = std::max(max_sum, curr_sum);
        }
        return max_sum;
    }
};

//time:O(N)
//space:O(1)

/*
one dimension dynamic programing
curr_sum>=0 nums[i] add to the subarray
curr_num<0 nums[i] is the new beginning of the subarray

1.minsum subarray
replace max with min

2.get the detailed maxsum subarray
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curr_sum = 0, max_sum = nums[0];
        int start = 0, end = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (curr_sum < 0)
            {
                start = i;
            }
            curr_sum = std::max(nums[i], curr_sum + nums[i]);
            if (curr_sum >= max_sum)
            {
                end = i;
            }
            max_sum = std::max(max_sum, curr_sum);
        }
        for (int i = start; i <= end; ++i)
        {
            std::cout << nums[i] << " ";
        }
        std::cout << std::endl;
        return max_sum;
    }
};
*/

class Solution2
{
public:
    int maxSubArray(vector<int> &nums)
    {
    }
};

#ifdef USE_GTEST
TEST(DSA, 53_maxSubArray)
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    int res = s.maxSubArray(nums);

    ASSERT_TRUE(res == 6);
}
#endif
